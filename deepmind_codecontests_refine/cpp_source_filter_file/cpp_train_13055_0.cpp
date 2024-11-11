#include <bits/stdc++.h>
#pragma comment(linker, "/STACK:100000000000,100000000000")
using namespace std;
const long long inf = 1e18 + 7;
const long long mod = 1e9 + 7;
const double eps = 1e-12;
const double PI = 2 * acos(0.0);
const double E = 2.71828;
int n;
int cnt[5];
int ans = 0;
void die() {
  puts("-1");
  exit(0);
}
int main(void) {
  scanf("%d", &n);
  for (long long(i) = 0; (i) < (long long)(n); (i)++) {
    int x;
    scanf("%d", &x);
    ++cnt[x];
  }
  int x = min(cnt[1], cnt[2]);
  ans += x;
  cnt[1] -= x;
  cnt[2] -= x;
  cnt[3] += x;
  if (cnt[1] > cnt[2]) {
    ans += (cnt[1] / 3) * 2;
    cnt[3] += cnt[1] / 3;
    cnt[1] %= 3;
    if (cnt[1]) {
      if (cnt[1] == 1) {
        if (cnt[3]) {
          ++ans;
        } else if (cnt[4] >= 2) {
          ans += 2;
        } else
          die();
      } else {
        if (cnt[3] >= 2) {
          ans += 2;
        } else if (cnt[4]) {
          ans += 2;
        } else
          die();
      }
    }
  } else {
    ans += cnt[2] / 3;
    cnt[3] += (cnt[2] / 3) * 2;
    cnt[2] %= 3;
    if (cnt[2]) {
      if (cnt[2] == 1) {
        if (cnt[4]) {
          ans += 1;
        } else if (cnt[3] >= 2) {
          ans += 2;
        } else
          die();
      } else {
        cnt[4]++;
        ans += 2;
      }
    }
  }
  printf("%d\n", ans);
  return 0;
}
