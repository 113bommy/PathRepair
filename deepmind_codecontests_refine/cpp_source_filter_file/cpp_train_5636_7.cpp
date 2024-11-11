#include <bits/stdc++.h>
using namespace std;
int a[10];
int main() {
  int n;
  long long ans = 0;
  cin >> n;
  for (int i = 1; i <= n; i++) a[i % 9]++, ans -= n / i;
  for (int i = 1; i < 9; i++)
    for (int j = 0; j < 9; j++) ans += 1ll * a[i] * a[j] * a[i * j % 9];
  cout << ans << endl;
  return 0;
}
