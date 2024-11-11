#include <bits/stdc++.h>
using namespace std;
template <typename T>
ostream &operator<<(ostream &os, vector<T> v) {
  os << "[";
  for (auto it : v) os << it << " ";
  return os << "]";
}
template <typename K, typename V>
ostream &operator<<(ostream &os, pair<K, V> v) {
  return os << "(" << v.first << ", " << v.second << ")";
}
int n, m, c0, d0;
int A[11][4];
long long mem[11][1005];
long long dp(int pos, int n) {
  if (n == 0) return 0;
  if (pos == m) return 1ll * (n / c0) * d0;
  long long &ret = mem[pos][n];
  if (~ret) return ret;
  ret = 0;
  int k = A[pos][0] / A[pos][1];
  for (int i = 0; i <= k; ++i) {
    if (n >= A[pos][2] * i)
      ret = max(ret, dp(pos + 1, n - A[pos][2] * i) + A[pos][3] * i);
  }
  ret = max(ret, 1ll * (n / c0) * d0);
  return ret;
}
int main() {
  cin >> n >> m >> c0 >> d0;
  for (int i = 0; i < m; ++i)
    for (int j = 0; j < 4; ++j) cin >> A[i][j];
  memset(mem, -1, sizeof mem);
  cout << dp(0, n) << endl;
  return 0;
}
