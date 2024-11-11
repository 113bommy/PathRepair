#include <bits/stdc++.h>
using namespace std;
int fn(int x) {
  int y = 0;
  while (x) {
    y += x % 10;
    x /= 10;
  }
  if (y < 10) return y;
  return fn(y);
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  int n;
  cin >> n;
  int count[100] = {};
  int64_t ans = 0;
  for (int i = 1; i <= n; i++) ans -= (n / i);
  for (int i = 1; i <= n; i++) count[fn(i)]++;
  for (int i = 1; i <= 9; i++)
    for (int j = 1; j <= 9; j++)
      ans += 1LL * count[i] * count[j] * count[fn(i * j)];
  cout << ans;
  return 0;
}
