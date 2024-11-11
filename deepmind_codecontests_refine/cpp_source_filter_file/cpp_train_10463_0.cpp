#include <bits/stdc++.h>
using namespace std;
int n, a[233333], ans = 233333333;
int main() {
  cin >> n;
  for (int i = 1; i <= n; i++) scanf("%d", &a[i]);
  sort(a + 1, a + n + 1);
  for (int i = 1; i <= n / 2; i++) ans = min(ans, a[i + n / 2] - a[i]);
  cout << ans << endl;
  return 0;
}
