#include <bits/stdc++.h>
using namespace std;
int main(void) {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  int t;
  cin >> t;
  while (t--) {
    int a, b, c;
    cin >> a >> b >> c;
    int ans = 987654321;
    int ansa, ansb, ansc;
    for (int i = 0; i < b; i++) {
      int cur = b - i;
      int cura = a;
      int cura2 = a;
      int curc = c;
      int curnum = 0;
      int ret = curc % cur;
      curnum = i + min(ret, cur - ret);
      while (cur % cura != 0 && cur % cura2 != 0) {
        cura--;
        cura2++;
        curnum++;
        if (curnum >= ans) break;
      }
      if (ans > curnum) {
        ans = curnum;
        if (cur % cura == 0)
          ansa = cura;
        else
          ansa = cura2;
        ansb = cur;
        if (ret > cur - ret)
          ansc = curc + (cur - ret);
        else
          ansc = curc - ret;
      }
    }
    for (int i = 1; b + i <= 10010; i++) {
      int cur = b + i;
      int cura = a;
      int cura2 = a;
      int curc = c;
      int curnum = 0;
      int ret = curc % cur;
      curnum = i + min(ret, cur - ret);
      while (cur % cura != 0 && cur % cura2 != 0) {
        cura--;
        cura2++;
        curnum++;
        if (curnum >= ans) break;
      }
      if (ans > curnum) {
        ans = curnum;
        if (cur % cura == 0)
          ansa = cura;
        else
          ansa = cura2;
        ansb = cur;
        if (ret > cur - ret)
          ansc = curc + (cur - ret);
        else
          ansc = curc - ret;
      }
    }
    cout << ans << '\n';
    cout << ansa << ' ' << ansb << ' ' << ansc << '\n';
  }
  return 0;
}
