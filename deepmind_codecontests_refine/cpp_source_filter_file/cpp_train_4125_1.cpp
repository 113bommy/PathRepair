#include <bits/stdc++.h>
using namespace std;
template <class T>
bool uin(T &a, T b) {
  return a > b ? (a = b, true) : false;
}
template <class T>
bool uax(T &a, T b) {
  return a < b ? (a = b, true) : false;
}
const long long P = 1000000000 + 7;
const int maxn = 1100000;
vector<long long> cnt[3];
long long a[3][maxn];
int n, l, m;
vector<long long> mul(vector<long long> a, vector<long long> b) {
  vector<long long> c(m);
  for (int i = 0; i < (int)(m); ++i)
    for (int j = 0; j < (int)(m); ++j) (c[(i + j) % m] += a[i] * b[j]) %= P;
  return c;
}
vector<long long> deg(vector<long long> a, long long d) {
  vector<long long> c(m);
  c[0] = 1;
  while (d) {
    if (d & 1) c = mul(c, a);
    a = mul(a, a);
    d /= 2;
  }
  return c;
}
int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.precision(10);
  cout << fixed;
  cin >> n >> l >> m;
  for (int i = 0; i < (int)(3); ++i) cnt[i].resize(m);
  for (int i = 0; i < (int)(3); ++i)
    for (int j = 0; j < (int)(n); ++j) {
      int x;
      cin >> x;
      a[i][j] = x;
      ++cnt[i][x % m];
    }
  vector<long long> y = mul(cnt[0], deg(cnt[1], l - 2));
  long long ans = 0;
  for (int i = 0; i < (int)(n); ++i)
    ans += y[(2 * m - a[1][i] % m - a[2][i] % m) % m];
  cout << ans << '\n';
  return 0;
}
