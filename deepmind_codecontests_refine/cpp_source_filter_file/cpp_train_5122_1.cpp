#include <bits/stdc++.h>
using namespace std;
const int INF = 1000000001;
const long long int INFLL = 1000000000000000001;
const long double EPS = 1e-6;
unordered_map<long long int, int> L, R;
unordered_map<long long int, int> Gen(const vector<long long int>& T) {
  int n = T.size();
  unordered_map<long long int, int> result;
  for (int i = 0; i < (1 << n); i++) {
    long long int s = 0;
    int cnt = 0;
    for (int j = 0; j < n; j++)
      if (i & (1 << j)) {
        s += T[j];
        cnt++;
      }
    if (result.count(s) == 0) result[s] = INF;
    result[s] = min(result[s], cnt);
  }
  return result;
}
int Greedy(long long int n) { return __builtin_popcountll(n); }
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  long long int n, p;
  cin >> n >> p;
  vector<long long int> l, r;
  for (int i = 0; i < 16; i++) l.push_back((1 << i) + p);
  for (int i = 16; i < 32; i++) r.push_back((1 << i) + p);
  L = Gen(l);
  R = Gen(r);
  int best = INF;
  for (const pair<long long int, int>& x : L) {
    long long int y = n - x.first;
    if (R.count(y) == 0) continue;
    int rr = x.second + R[y];
    best = min(best, rr);
  }
  for (int i = 0; i <= min(100000, best); i++) {
    long long int amount = n - p * i;
    if (amount < i) continue;
    int denoms = Greedy(amount);
    if (denoms > i) continue;
    best = min(best, max(i, denoms));
  }
  if (best == INF)
    cout << "-1\n";
  else
    cout << best;
  return 0;
}
