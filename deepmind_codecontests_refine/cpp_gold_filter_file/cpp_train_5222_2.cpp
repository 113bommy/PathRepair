#include <bits/stdc++.h>
#pragma GCC optimize("Ofast")
#pragma GCC optimize("unroll-loops")
#pragma GCC target("sse4")
using namespace std;
long long a[100];
long long done[100];
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  long long n, h, m;
  cin >> n >> h >> m;
  long long i, j;
  for (i = 1; i <= m; i++) {
    long long l, r, x;
    cin >> l >> r >> x;
    for (j = l; j <= r; j++)
      if (!done[j]) {
        a[j] = x;
        done[j] = 1;
      } else
        a[j] = min(a[j], x);
  }
  for (i = 1; i <= n; i++)
    if (!done[i]) a[i] = h;
  long long sum = 0;
  for (i = 1; i <= n; i++) sum = sum + (a[i] * a[i]);
  cout << sum;
  return 0;
}
