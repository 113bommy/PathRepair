#include <bits/stdc++.h>
using namespace std;
int fin(int a[], int I, int k, int n) {
  int x = 0;
  for (int i = I; i <= n; i += k) x += a[i];
  return x;
}
int main() {
  int n, k, a[101];
  cin >> n >> k;
  for (int i = 1; i <= n; i++) cin >> a[i];
  int sum = 0;
  for (int i = 1; i <= n; i++) sum += a[i];
  int ans = 0;
  for (int i = 1; i <= k; i++) ans = max(abs(ans), abs(ans - fin(a, i, k, n)));
  cout << ans << endl;
}
