#include <bits/stdc++.h>
using namespace std;
struct point {
  char s[12];
  int h;
} a[3005];
bool cmp(point a, point b) {
  if (a.h < b.h)
    return true;
  else
    return false;
}
int ans[5005];
int main() {
  int n;
  scanf("%d", &n);
  for (int i = 1; i <= n; i++) {
    cin >> a[i].s >> a[i].h;
  }
  sort(a + 1, a + n + 1, cmp);
  if (a[1].h >= 1) {
    puts("-1");
    return 0;
  }
  int now = 1;
  ans[1] = 1;
  for (int i = 2; i <= n; i++) {
    if (a[i].h >= i) {
      puts("-1");
      return 0;
    }
    if (a[i].h == 0) {
      ans[i] = i, now++;
      continue;
    } else {
      ans[i] = i - a[i].h + 1;
      for (int j = 1; j <= i - 1; j++) {
        if (ans[j] >= ans[i]) ans[j]++;
      }
    }
  }
  for (int i = 1; i <= n; i++) printf("%s %d\n", a[i].s, ans[i]);
  return 0;
}
