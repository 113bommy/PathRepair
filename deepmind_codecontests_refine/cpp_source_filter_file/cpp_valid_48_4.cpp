#include <bits/stdc++.h>
using namespace std;
long long gcd(long long a, long long b) { return b ? gcd(b, a % b) : a; }
const int N = 3e5 + 10;
const double eps = 1e-5;
long long arr[N], brr[N], d[N], pre[N];
long long mi[30][N], mx[30][N];
long long quemx(int l, int r) {
  int d = log(r - l + 1);
  return max(mx[d][l], mx[d][r - (1 << d)]);
}
long long quemi(int l, int r) {
  int d = log(r - l + 1);
  return min(mi[d][l], mi[d][r - (1 << d)]);
}
int main() {
  std::ios::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  int n, q;
  cin >> n >> q;
  for (int i = 1; i <= n; i++) {
    cin >> arr[i];
  }
  for (int i = 1; i <= n; i++) {
    cin >> brr[i];
  }
  for (int i = 1; i <= n; i++) {
    pre[i] = brr[i] - arr[i] + pre[i - 1];
  }
  for (int i = 1; i <= n; i++) {
    mi[0][i] = pre[i];
    mx[0][i] = pre[i];
  }
  for (int i = 1; i < 30; i++) {
    for (int j = 1; j <= n; j++) {
      mi[i][j] = min(mi[i - 1][j], mi[i - 1][min(n, j + (1 << (i - 1)))]);
      mx[i][j] = max(mx[i - 1][j], mx[i - 1][min(n, j + (1 << (i - 1)))]);
    }
  }
  while (q--) {
    int l, r;
    cin >> l >> r;
    long long val = quemi(l, r) - pre[l - 1];
    if (val < 0 || pre[r] - pre[l - 1] != 0)
      cout << -1 << '\n';
    else
      cout << quemx(l, r) - pre[l - 1] << '\n';
  }
}
