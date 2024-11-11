#include <bits/stdc++.h>
using namespace std;
int n, m, s, t, x, y;
long long ans;
set<pair<int, int> > st;
int rd() {
  char c;
  while (c = getchar(), c < 'A')
    ;
  return c;
}
int main() {
  scanf("%d%d%d%d", &m, &n, &t, &s);
  y = (rd() == 'D') ? 1 : -1, x = (rd() == 'R') ? 1 : -1;
  ans = 1;
  for (int i = 1; i <= 2 * (n + m); i++) {
    st.insert(pair<int, int>(s, t));
    if (s == 1) x = 1;
    if (s == n) x = -1;
    if (t == 1) y = 1;
    if (t == m) y = -1;
    if (st.size() >= n + m - 2) return printf("%I64d\n", ans), 0;
    int z = min(x > 0 ? n - s : s - 1, y > 0 ? m - t : t - 1);
    ans += z, s += x * z, t += y * z;
  }
  return puts("-1"), 0;
}
