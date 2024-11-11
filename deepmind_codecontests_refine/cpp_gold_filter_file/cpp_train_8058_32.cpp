#include <bits/stdc++.h>
using namespace std;
int main() {
  int n, m;
  cin >> n >> m;
  int a[100005], b[100005], c[100005];
  for (int i = 0; i < n; i++) cin >> a[i];
  for (int i = 0; i < m; i++) cin >> b[i];
  bool bo[100005];
  for (int i = 0; i < 100005; i++) bo[i] = false;
  c[n] = 0;
  for (int i = n - 1; i >= 0; i--) {
    if (!bo[a[i]]) {
      bo[a[i]] = true;
      c[i] = c[i + 1] + 1;
    } else
      c[i] = c[i + 1];
  }
  for (int i = 0; i < m; i++) {
    cout << c[b[i] - 1] << endl;
  }
}
