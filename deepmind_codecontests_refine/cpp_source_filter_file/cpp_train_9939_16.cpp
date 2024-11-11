#include <bits/stdc++.h>
using namespace std;
int n, a[100005];
pair<int, int> lt[100005], f[100005], g[100005];
int d[100005], del;
long long ds;
int dd[100005], sl;
void tao() {
  lt[0] = pair<int, int>(1, 1);
  for (int i = 1; i <= n; ++i) {
    lt[i].first = (lt[i - 1].first * 2027LL) % 1000000007;
    lt[i].second = (lt[i - 1].second * 2017LL) % 1000000007;
  }
  int u = 1, v = n;
  while (u <= v && a[u] == a[v]) {
    ++u;
    --v;
    ++del;
  }
  if (u > v) {
    cout << (long long)n * (n + 1) / 2;
    exit(0);
  }
  ++del;
  for (int i = u; i <= v; ++i) a[i - u + 1] = a[i];
  n = v - u + 1;
  for (int i = 1; i <= n; ++i) dd[a[i]]++;
  for (int i = 1; i <= n; ++i)
    if (dd[i] % 2) ++sl;
  if (n % 2 == 0 && sl > 0) {
    cout << 0;
    exit(0);
  }
  if (n % 2 && sl > 1) {
    cout << 0;
    exit(0);
  }
  ds += (long long)del * del;
  for (int i = 1; i <= n; ++i) {
    f[i].first = (f[i - 1].first + lt[a[i]].first) % 1000000007;
    f[i].second = (f[i - 1].second + lt[a[i]].second) % 1000000007;
  }
  for (int i = n; i >= 1; --i) {
    g[i].first = (g[i + 1].first + lt[a[i]].first) % 1000000007;
    g[i].second = (g[i + 1].second + lt[a[i]].second) % 1000000007;
  }
  u = n / 2;
  while (a[u] == a[n - u + 1] && u) {
    d[u] = 1;
    --u;
  }
}
void tinh1() {
  int m = (n % 2) ? (n + 1) / 2 + 1 : n / 2 + 1;
  for (int i = n; i >= m; --i) {
    dd[a[i]] -= 2;
    if (dd[a[i]] < 0) return;
    ds += del;
  }
}
void tinh2() {
  memset(dd, 0, sizeof(dd));
  for (int i = 1; i <= n; ++i) dd[a[i]]++;
  int m = (n % 2) ? (n + 1) / 2 - 2 : n / 2 - 1;
  for (int i = 1; i <= m; ++i) {
    dd[a[i]] -= 2;
    if (dd[a[i]] < 0) return;
    ds += del;
  }
}
int main() {
  cin.tie(0);
  cout.tie(0);
  ios::sync_with_stdio(0);
  cin >> n;
  for (int i = 1; i <= n; ++i) cin >> a[i];
  tao();
  for (int i = 1; i <= n / 2; ++i)
    if (f[i] == g[n - i + 1] && (d[i + 1] || i == n / 2)) ds += 2 * del;
  tinh1();
  tinh2();
  cout << ds;
}
