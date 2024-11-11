#include <bits/stdc++.h>
using namespace std;
const int MAXN = 200005;
int n, q, p, x, a[MAXN], b[MAXN], c[MAXN], o;
int main() {
  cin >> n;
  for (int i = 1; i <= n; i++) cin >> a[i];
  cin >> q;
  for (int i = 1; i <= n; i++) {
    cin >> o;
    if (o == 1) {
      cin >> p >> x;
      c[p] = i, a[p] = x;
    } else {
      cin >> p;
      b[i] = p;
    }
  }
  for (int i = q - 1; i >= 0; i--) b[i] = max(b[i], b[i + 1]);
  for (int i = 1; i <= n; i++) cout << max(a[i], b[c[i]]) << " ";
}
