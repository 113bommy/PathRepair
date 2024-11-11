#include <bits/stdc++.h>
using namespace std;
inline bool start_game(void) {
  static char str[20];
  scanf("%s", str);
  return str[0] == 's';
}
inline int interact(int x, int y) {
  static char str[20];
  printf("? %d %d\n", x, y);
  fflush(stdout);
  scanf("%s", str);
  return str[0] == 'x';
}
inline int solve(void) {
  if (interact(0, 1)) return 1;
  for (int t = 0;; t++)
    if (interact(1 << t, 1 << (t + 1))) {
      int l = 1 << t, r = 1 << (t + 1), ans;
      while (l <= r) {
        int mid = (l + r) / 2;
        if (interact(1 << t, mid))
          r = (ans = mid) - 1;
        else
          l = mid + 1;
      }
      return ans;
    }
}
int main() {
  while (start_game()) {
    printf("! %d\n", solve());
    fflush(stdout);
  }
  return 0;
}
