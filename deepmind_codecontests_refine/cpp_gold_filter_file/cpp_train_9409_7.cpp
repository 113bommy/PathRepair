#include <bits/stdc++.h>
using namespace std;
template <class T>
ostream& operator<<(ostream& os, const vector<T>& vec) {
  for (auto& vi : vec) os << vi << " ";
  return os;
}
template <class T>
inline bool chmin(T& a, T b) {
  if (a > b) {
    a = b;
    return 1;
  }
  return 0;
}
const int INF = (int)1e9 + 7;
int main() {
  int n;
  cin >> n;
  vector<vector<int>> a(n, vector<int>(n));
  for (auto& ai : a)
    for (auto& aij : ai) cin >> aij;
  vector<int> p(n);
  for (auto& pi : p) cin >> pi, pi--;
  reverse(begin(p), end(p));
  vector<vector<int>> mat(n, vector<int>(n));
  for (int i = 0; i < n; i++)
    for (int j = 0; j < n; j++) {
      mat[i][j] = a[p[i]][p[j]];
    }
  vector<vector<int>> dist(n, vector<int>(n, INF));
  for (int i = 0; i < n; i++) dist[i][i] = 0;
  vector<long long> res(n);
  for (int k = 0; k <= n - 1; k++) {
    for (int i = 0; i < k; i++)
      for (int j = 0; j < k; j++) {
        chmin(dist[k][j], mat[k][i] + dist[i][j]);
        chmin(dist[i][k], dist[i][j] + mat[j][k]);
      }
    for (int i = 0; i < k; i++)
      for (int j = 0; j < k; j++) {
        chmin(dist[i][j], dist[i][k] + dist[k][j]);
      }
    for (int i = 0; i <= k; i++)
      for (int j = 0; j <= k; j++) {
        res[k] += dist[i][j];
      }
  }
  reverse(begin(res), end(res));
  cout << res << endl;
  return 0;
}
