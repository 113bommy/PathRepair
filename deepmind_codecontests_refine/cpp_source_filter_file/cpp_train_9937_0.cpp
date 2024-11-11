#include <bits/stdc++.h>
const int maxn = 1e5 + 10;
using namespace std;
int n, m;
long long a[maxn], b[maxn];
long long min(long long a, long long b) { return a < b ? a : b; }
int main() {
  cin >> n >> m;
  long long suma = 0, sumb = 0;
  for (int i = 1; i <= n; i++) cin >> a[i], suma += a[i];
  for (int i = 1; i <= m; i++) cin >> b[i], sumb += b[i];
  sort(a + 1, a + n + 1);
  sort(b + 1, b + n + 1);
  long long ansa = suma, ansb = sumb;
  for (int i = 1; i < m; i++) ansa += min(suma, b[i]);
  for (int i = 1; i < n; i++) ansb += min(sumb, a[i]);
  cout << min(ansa, ansb);
  return 0;
}
