#include <bits/stdc++.h>
using namespace std;
int main() {
  int n, m, s, f, t;
  cin >> n >> m;
  for (int i = 0; i < n; i++) {
    scanf("%d%d%d", &s, &f, &t);
    int sign = (t - 1) / (m - 1), ans = 0, now;
    if (t == 0) sign = 0;
    if (sign % 2 == 0) {
      now = (t % (m - 1));
      if (!now) now = m - 1;
      now++;
      if (t == 0) now = 1;
      if (now <= s) {
        ans += (s - now);
        if (f >= s)
          ans += (f - s);
        else
          ans += (m - s + m - f);
      } else {
        ans += (m - now + m - s);
        if (f <= s)
          ans += (f - s);
        else
          ans += (s - 1 + f - 1);
      }
    } else {
      now = (t % (m - 1));
      if (!now) now = m - 1;
      now = m - now;
      if (now >= s) {
        ans += (now - s);
        if (f <= s)
          ans += (s - f);
        else
          ans += (s - 1 + f - 1);
      } else {
        ans += (now - 1 + s - 1);
        if (f >= s)
          ans += (f - s);
        else
          ans += (m - s + m - f);
      }
    }
    if (s == f) ans = 0;
    printf("%d\n", ans + t);
  }
  return 0;
}
