#include <bits/stdc++.h>
using namespace std;
long long n, a[100100], q, b[100100], x[100100];
int main() {
  cin >> n;
  for (int i = 1; i <= n; i++) cin >> a[i];
  long u, v, w;
  cin >> q;
  for (int i = 1; i <= q; i++) {
    cin >> u;
    if (u == 2) {
      cin >> v;
      b[i] = v;
    } else {
      cin >> v >> w;
      x[v] = i;
      a[v] = w;
    }
  }
  for (int i = n - 1; i >= 1; i--) b[i] = max(b[i], b[i + 1]);
  for (int i = 1; i <= n; i++) cout << max(a[i], b[x[i] + 1]) << " ";
}
