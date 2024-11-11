#include <bits/stdc++.h>
using namespace std;
int a, ta, b, tb, h, m;
int t_begin, t_end, t, ans;
int get_time(int h, int m) { return 60 * h + m; }
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  int i;
  scanf("%d %d", &a, &ta);
  scanf("%d %d", &b, &tb);
  scanf("%d:%d", &h, &m);
  t_begin = get_time(5, 0);
  t_end = get_time(23, 59);
  t = get_time(h, m);
  for (i = t_begin; i + tb <= t_end; i += b) {
    if (i + tb > t) {
      if (t + ta > i) {
        ++ans;
      }
    }
  }
  printf("%d\n", ans);
  return 0;
}
