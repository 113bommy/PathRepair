#include <bits/stdc++.h>
using namespace std;
int main() {
  int n, m;
  cin >> n >> m;
  for (int i = 0; i < n; ++i) {
    int s, f, t;
    scanf("%d%d%d", &s, &f, &t);
    int a = t % (2 * m - 2);
    if (s == f) {
      printf("%d\n", t);
      continue;
    }
    bool up = 1;
    if (a > m - 1) up = 0;
    int ans = t;
    if (up)
      ans += (s - a - 1);
    else
      ans += (m - s + m - 1 - a);
    if (up && a > s - 1) {
      ans = t + (m - 1 - a) + (m - s);
      up = 0;
    } else if (!up && s > (2 * m - 1 - a)) {
      ans = t + (2 * m - 2 - a) + (s - 1);
      up = 1;
    }
    a = ans % (2 * m - 1);
    if (up) {
      if (s < f)
        ans += (f - s);
      else
        ans += m - s + m - f;
    } else {
      if (s > f)
        ans += (s - f);
      else
        ans += s + f - 2;
    }
    printf("%d\n", ans);
  }
  return 0;
}
