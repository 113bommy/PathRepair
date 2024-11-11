#include <bits/stdc++.h>
using namespace std;
const int INF = 1000000001;
const long long int INFLL = 1000000000000000001;
const long double EPS = 1e-6;
int k;
vector<pair<int, int>> operations;
map<int, int> M;
unordered_map<int, vector<int>> Gen(const vector<int>& T) {
  int n = (int)T.size();
  unordered_map<int, vector<int>> result;
  for (int i = 0; i < (1 << n); i++) {
    int s = 0;
    for (int j = 0; j < n; j++)
      if (i & (1 << j)) s += T[j];
    result[s % k].push_back(i);
  }
  return result;
}
vector<int> RGen(const vector<int>& T) {
  vector<int> l(T.begin(), T.begin() + T.size() / 2);
  vector<int> r(T.begin() + T.size() / 2, T.end());
  unordered_map<int, vector<int>> left = Gen(l);
  unordered_map<int, vector<int>> right = Gen(r);
  vector<int> result;
  for (const pair<int, vector<int>>& x : left) {
    int rr = (k - x.first) % k;
    if (right.count(rr) == 0) continue;
    for (int a : x.second)
      for (int b : right[rr]) result.push_back(a + (b << (int)l.size()));
  }
  return result;
}
vector<int> Vectorize(const map<int, int>& MM) {
  vector<int> T;
  for (const pair<int, int>& x : MM)
    for (int i = 0; i < x.second; i++) T.push_back(x.first);
  return T;
}
bool CompareMasks(int x, int y) {
  return __builtin_popcount(x) < __builtin_popcount(y);
}
int UpdateMap(const vector<int>& items, int bitmask, int by) {
  int sum = 0;
  for (int i = 0; i < (int)items.size(); i++)
    if (bitmask & (1 << i)) {
      M[items[i]] += by;
      sum += items[i];
    }
  return sum;
}
int AddOperations(const vector<int>& items, int bitmask) {
  int last = 0, opers = 0;
  for (int i = 0; i < (int)items.size(); i++)
    if (bitmask & (1 << i)) {
      if (last > 0) {
        operations.push_back(make_pair(last, items[i]));
        opers++;
      }
      last += items[i];
    }
  return opers;
}
int F(int x) {
  if (x % k != 0) return x;
  return F(x / k);
}
void Go(int lvl) {
  vector<int> T = Vectorize(M);
  if ((T.size() == 1) && (T.front() == 1)) {
    cout << "YES\n";
    for (const pair<int, int>& op : operations)
      cout << op.first << " " << op.second << "\n";
    exit(0);
  }
  random_shuffle(T.begin(), T.end());
  vector<int> R = RGen(T);
  sort(R.begin(), R.end(), CompareMasks);
  vector<int> RR;
  int max_tests = 4;
  for (int i = 0; i < min((int)R.size() + 1, max_tests) / 2; i++)
    RR.push_back(R[i]);
  if (min((int)R.size() + 1, max_tests) / 2 < max_tests) {
    for (int i = 0; i < min((int)R.size(), max_tests) / 2; i++)
      RR.push_back(R[R.size() - 1 - i]);
  }
  for (int x : RR) {
    if (__builtin_popcount(x) <= 1) continue;
    int s = F(UpdateMap(T, x, -1));
    M[s]++;
    int ops = AddOperations(T, x);
    Go(lvl + 1);
    M[s]--;
    for (int i = 0; i < ops; i++) operations.pop_back();
    UpdateMap(T, x, +1);
  }
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  int n;
  cin >> n >> k;
  for (int i = 0; i < n; i++) {
    int x;
    cin >> x;
    M[x]++;
  }
  Go(0);
  cout << "NO\n";
  return 0;
}
