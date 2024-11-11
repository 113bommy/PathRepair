#include <bits/stdc++.h>
using namespace std;
int x, y, a[200010], ans;
int main() {
  cin >> x;
  for (int i = 1; i <= x; i++) cin >> a[i];
  sort(a + 1, a + x + 1);
  for (int i = 1; i < x; i++) ans += a[i];
  cout << abs(a[x] - ans + 1);
}
