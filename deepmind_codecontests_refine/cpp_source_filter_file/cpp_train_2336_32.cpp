#include <bits/stdc++.h>
using namespace std;
template <class T>
ostream& operator<<(ostream& os, vector<T> V) {
  os << "[ ";
  for (auto v : V) os << v << " ";
  return os << "]";
}
template <class L, class R>
ostream& operator<<(ostream& os, pair<L, R> P) {
  return os << "(" << P.first << "," << P.second << ")";
}
const unsigned long long INF = 1e18 + 7;
const int N = 105;
const int M = 22;
pair<unsigned long long, pair<unsigned long long, unsigned long long> > X[N];
unsigned long long n, b, m;
unsigned long long dp[1 << 22];
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  cin >> n >> m >> b;
  for (int i = 0; i < n; i++) {
    int mi;
    cin >> X[i].second.first >> X[i].first >> mi;
    int curr = 0, no;
    for (int j = 0; j < mi; j++) {
      cin >> no;
      no--;
      curr += (1 << no);
    }
    X[i].second.second = curr;
  }
  sort(X, X + n);
  for (int j = 0; j < (1 << m); j++) dp[j] = INF;
  dp[0] = 0;
  unsigned long long res = INF;
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < (1 << m); j++) {
      if (dp[j] < INF)
        dp[j | (X[i].second.second)] =
            min(dp[j | X[i].second.second], dp[j] + X[i].second.first);
      if (dp[(1 << m) - 1] < INF) {
        res = min(res, dp[(1 << m) - 1] + b * X[i].first);
      }
    }
  }
  if (res == INF)
    cout << -1 << endl;
  else
    cout << res << endl;
  return 0;
}
