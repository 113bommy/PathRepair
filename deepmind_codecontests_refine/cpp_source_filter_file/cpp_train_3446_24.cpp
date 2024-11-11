#include <bits/stdc++.h>
using namespace std;
template <class T>
void dbs(string str, T t) {
  cerr << str << " : " << t << "\n";
}
template <class T, class... S>
void dbs(string str, T t, S... s) {
  int idx = str.find(',');
  cerr << str.substr(0, idx) << " : " << t << ",";
  dbs(str.substr(idx + 1), s...);
}
template <class S, class T>
ostream& operator<<(ostream& os, const pair<S, T>& p) {
  return os << "(" << p.first << ", " << p.second << ")";
}
template <class T>
ostream& operator<<(ostream& os, const vector<T>& p) {
  os << "[ ";
  for (auto& it : p) os << it << " ";
  return os << "]";
}
template <class T>
ostream& operator<<(ostream& os, const set<T>& p) {
  os << "[ ";
  for (auto& it : p) os << it << " ";
  return os << "]";
}
template <class S, class T>
ostream& operator<<(ostream& os, const map<S, T>& p) {
  os << "[ ";
  for (auto& it : p) os << it << " ";
  return os << "]";
}
template <class T>
void prc(T a, T b) {
  cerr << "[";
  for (T i = a; i != b; ++i) {
    if (i != a) cerr << ", ";
    cerr << *i;
  }
  cerr << "]\n";
}
const int BLOCK_SIZE = 350;
const int N = 300010;
int a[N + 1];
long long dp[N + 1];
long long answer1[N + 1];
vector<pair<pair<int, int>, int>> queries[BLOCK_SIZE + 1];
vector<pair<pair<int, int>, int>> bigQuery;
int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  int n;
  cin >> n;
  for (int i = (int)(1); i <= (int)(n); i++) {
    int temp;
    cin >> temp;
    a[i] = temp;
  }
  int m;
  cin >> m;
  for (int i = (int)(1); i <= (int)(n); i++) {
    int a1, b1;
    cin >> a1 >> b1;
    if (b1 <= BLOCK_SIZE) {
      queries[b1].push_back(make_pair(make_pair(a1, b1), i));
    } else {
      bigQuery.push_back(make_pair(make_pair(a1, b1), i));
    }
  }
  for (int i = (int)(1); i <= (int)(BLOCK_SIZE); i++) {
    for (int j = (int)(0); j <= (int)(n); j++) dp[j] = 0;
    for (int j = (int)(n); j >= (int)(1); --j) {
      if (j + i > n)
        dp[j] = a[j];
      else
        dp[j] = dp[j + i] + a[j];
    }
    for (auto query : queries[i]) {
      answer1[query.second] = dp[query.first.first];
    }
  }
  for (auto query : bigQuery) {
    for (int i = query.first.first; i <= n; i += query.first.second) {
      answer1[query.second] += (long long)a[i];
    }
  }
  for (int i = (int)(1); i <= (int)(m); i++) {
    cout << answer1[i] << "\n";
  }
  return 0;
}
