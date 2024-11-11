#include <bits/stdc++.h>
using namespace std;
const int N = 3e5 + 2;
const int MOD = 1e9 + 7;
const int bm = 1;
int n, m;
int a[N], b[N], s[N];
long long tong;
long long f[N], d[N];
void sinh() {
  freopen(".inp", "w", stdout);
  srand(time(0));
}
int main() {
  ios_base::sync_with_stdio(0);
  cin >> n >> m;
  for (int i = 1; i <= n; i++)
    cin >> a[i] >> b[i], s[i] = a[i] - b[i], tong += b[i];
  sort(s + 1, s + n + 1);
  for (int i = 1; i <= n; i++) f[i] = f[i - 1] + s[i];
  for (int i = 1; i <= n; i++) {
    int first = b[i] - a[i];
    long long kq = 1ll * a[i] * n + tong - a[i] - b[i];
    int second = lower_bound(s + 1, s + n + 1, a[i] - b[i]) - s - 1;
    d[i] = kq + first * second + f[second];
  }
  while (m--) {
    int u, v, MIN;
    cin >> u >> v;
    MIN = min(a[v] + b[u], a[u] + b[v]);
    d[u] -= MIN, d[v] -= MIN;
  }
  for (int i = 1; i <= n; i++) cout << d[i] << " ";
}
