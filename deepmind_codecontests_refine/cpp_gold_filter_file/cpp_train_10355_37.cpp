#include <bits/stdc++.h>
using namespace std;
inline int foo(int h, int d) {
  int x = (d ? h / d : 1e9);
  h -= d * x;
  if (x != 1e9)
    while (h > 0) h -= d, x++;
  return x;
}
bool ok(int HPa, int ATKa, int DEFa, int HPb, int ATKb, int DEFb) {
  int Da = max(0, ATKb - DEFa);
  int Db = max(0, ATKa - DEFb);
  if (Da == 0 && Db == 0) return false;
  int za = foo(HPa, Da);
  int zb = foo(HPb, Db);
  return za > zb;
}
int main() {
  int HPa, ATKa, DEFa, HPb, ATKb, DEFb, h, a, d;
  cin >> HPa >> ATKa >> DEFa >> HPb >> ATKb >> DEFb >> h >> a >> d;
  int res = 1e9;
  for (int i = 0; i <= 21111; i++)
    for (int j = 0; j <= 211; j++)
      for (int k = 0; k <= 211; k++)
        if (i * h + j * a + k * d < res &&
            ok(HPa + i, ATKa + j, DEFa + k, HPb, ATKb, DEFb)) {
          res = min(res, i * h + j * a + k * d);
          if (res == 0) {
            int zzz;
            zzz++;
            zzz--;
          }
        }
  cout << res << "\n";
  return 0;
}
