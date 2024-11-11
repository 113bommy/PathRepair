#include <bits/stdc++.h>
using namespace std;
int a[200010];
int main() {
  int n, x, f, ans = 0;
  cin >> n;
  for (int i = 0; i < n; i++) scanf("%d", &a[i]);
  cin >> x >> f;
  for (int i = 0; i < n; i++) ans += (a[i] + f - 1) / (x + f) * f;
  cout << ans;
}
