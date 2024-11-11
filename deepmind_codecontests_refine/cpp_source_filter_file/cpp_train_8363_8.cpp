#include <bits/stdc++.h>
using namespace std;
const int MAGIC = 3e8;
const int INF = 0x3f3f3f3f;
int main() {
  int n, s;
  int cnt3 = 0, cnt4 = 0, cnt5 = 0;
  scanf("%d%d", &n, &s);
  for (int i = 1; i <= n; i++) {
    int x;
    scanf("%d", &x);
    if (x == 3)
      cnt3++;
    else if (x == 4)
      cnt4++;
    else
      cnt5++;
  }
  int ans = INF, ans3, ans4, ans5;
  for (int cur3 = s / (cnt3 + cnt4 + cnt5); cur3 >= 0; cur3--) {
  ReLoop:
    for (int cur4 =
             min((s - cur3 * cnt3) / (cnt4 + cnt5), (ans - cur3 * cnt3) / cnt4);
         cur4 >= cur3 && cur3 * cnt3 - cur4 * cnt4 < ans; cur4--) {
      int cur5 = (s - cur3 * cnt3 - cur4 * cnt4) / cnt5;
      if (cur5 * cnt5 - cur4 * cnt4 >= ans) break;
      if (cur5 * cnt5 + cur3 * cnt3 + cur4 * cnt4 == s) {
        int curAns =
            abs(cur3 * cnt3 - cnt4 * cnt4) + abs(cur4 * cnt4 - cur5 * cnt5);
        if (curAns < ans) {
          ans = curAns;
          ans3 = cur3;
          ans4 = cur4;
          ans5 = cur5;
        }
        static int counter;
        if (++counter > MAGIC) {
          cur3 = 0;
          goto ReLoop;
        }
      }
    }
  }
  if (ans == INF)
    puts("-1");
  else
    printf("%d %d %d\n", ans3, ans4, ans5);
  return 0;
}
