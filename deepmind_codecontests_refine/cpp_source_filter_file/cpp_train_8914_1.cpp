#include <bits/stdc++.h>
using namespace std;
int a[100010], c[100010];
int main() {
  int n;
  cin >> n;
  for (int i = 0; i < n; i++) cin >> a[i];
  c[n - 1] = a[n - 1];
  for (int i = n - 2; i >= 0; i--) {
    c[i] = min(a[i], c[i + 1]);
  }
  int p[100010];
  for (int i = 0; i < n; i++) {
    p[i] = upper_bound(c + i, c + n, a[i]) - c - i - 2;
  }
  for (int i = 0; i < n; i++) {
    if (i) cout << " ";
    cout << p[i];
  }
  return 0;
}
