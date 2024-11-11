#include <bits/stdc++.h>
using namespace std;
int a[10010];
void solve() {
  int n;
  cin >> n;
  int sum = 0;
  for (int i = 0; i < n; i++) {
    cin >> a[i];
    sum += a[i];
  }
  if (sum % n) {
    cout << "-1" << endl;
    return;
  }
  int x;
  const int k = sum / n;
  cout << 3 * n - 3 << '\n';
  for (int i = 2; i <= n; ++i) {
    printf("%d %d %d\n", 1, i, x = ((-a[i]) % i + i) % i);
    a[1] -= x, a[i] += x;
    printf("%d %d %d\n", i, 1, x = a[i] / i);
    a[i] -= x * i, a[1] += x * i;
  }
  for (int i = 2; i <= n; ++i) {
    printf("%d %d %d\n", 1, i, x = k);
    a[1] -= x, a[i] += x;
  }
}
int main() {
  int t;
  cin >> t;
  while (t--) {
    solve();
  }
}
