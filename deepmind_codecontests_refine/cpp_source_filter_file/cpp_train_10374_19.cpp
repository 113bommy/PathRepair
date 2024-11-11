#include <bits/stdc++.h>
using namespace std;
int n;
const int maxn = 1e5 + 5;
int a[maxn];
int b[maxn];
int c[maxn];
int main() {
  cin.tie(0), ios_base::sync_with_stdio(false);
  cin >> n;
  for (int i = 1; i <= n; ++i) cin >> a[i];
  b[n] = n, c[n] = a[n];
  for (int i = n - 1; i > 0; --i) {
    if (a[i] < a[b[i + 1]])
      b[i] = i, c[i] = a[i];
    else
      b[i] = b[i + 1], c[i] = a[b[i + 1]];
  }
  for (int i = 1; i <= n; ++i) {
    int t = lower_bound(c + i, c + n, a[i]) - c - 2 - i;
    if (t < 0) ++t;
    cout << max(t, -1) << ' ';
  }
  cout << endl;
  return 0;
}
