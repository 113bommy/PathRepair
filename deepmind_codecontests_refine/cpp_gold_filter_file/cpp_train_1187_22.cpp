#include <bits/stdc++.h>
using namespace std;
int cnt[5];
int main() {
  int n, x, s = 0, ans = 0;
  scanf("%d", &n);
  for (int i = 0; i < n; ++i) {
    scanf("%d", &x);
    ++cnt[x];
    s += x;
  }
  if (s < 3 || s == 5)
    ans = -1;
  else {
    int tmp = (cnt[1] > cnt[2] ? cnt[2] : cnt[1]);
    ans += tmp;
    cnt[1] -= tmp;
    cnt[2] -= tmp;
    cnt[3] += tmp;
    if (cnt[1]) {
      tmp = cnt[1] / 3;
      ans += tmp * 2;
      cnt[1] -= tmp * 3;
      cnt[3] += tmp;
      if (cnt[1] == 1 && cnt[3])
        ans += 1;
      else if (cnt[1])
        ans += 2;
    } else {
      tmp = cnt[2] / 3;
      ans += tmp * 2;
      cnt[2] -= tmp * 3;
      cnt[3] += tmp * 2;
      if (cnt[2] == 1 && cnt[4])
        ans += 1;
      else if (cnt[2])
        ans += 2;
    }
  }
  printf("%d\n", ans);
  return 0;
}
