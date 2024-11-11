#include <bits/stdc++.h>
using namespace std;
struct xy {
  int a, b;
} a[200005];
bool cmp(const xy& a, const xy& b) {
  if (a.b != b.b) return a.b < b.b;
  return a.a < b.a;
}
int main() {
  int i, n, x, y, ans = 0, s = -2e9;
  cin >> n;
  for (i = 1; i <= n; i++) {
    scanf("%d%d", &x, &y);
    a[i].a = x - y;
    a[i].b = x + y;
  }
  sort(a + 1, a + n + 1, cmp);
  for (i = 1; i <= n; i++) {
    if (s <= a[i].a) {
      ans++;
      s = a[i].b;
    }
  }
  cout << ans << endl;
  return 0;
}
