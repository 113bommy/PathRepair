#include <bits/stdc++.h>
using namespace std;
function<void(void)> ____ = []() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
};
int cap[2][3], type[7], tmp[2][3], res[7];
void ikun() {
  for (int i = 0; i < 2; i++)
    for (int j = 0; j < 3; j++) scanf("%d", &cap[i][j]);
  for (int i = 0; i < 7; i++) scanf("%d", &type[i]);
  if (type[0] + type[1] + type[2] + type[3] > cap[0][0] + cap[1][0] ||
      type[0] + type[1] + type[4] + type[5] > cap[0][1] + cap[1][1] ||
      type[0] + type[2] + type[4] + type[6] > cap[0][2] + cap[1][2]) {
    puts("-1");
    return;
  }
  for (int i = 0; i <= type[1]; i++)
    for (int j = 0; j <= type[2]; j++)
      for (int k = 0; k <= type[4]; k++) {
        tmp[0][0] = i + j;
        tmp[0][1] = i + k;
        tmp[i][2] = j + k;
        tmp[1][0] = type[1] + type[2] - i - j;
        tmp[1][1] = type[1] + type[4] - i - k;
        tmp[1][2] = type[2] + type[4] - j - k;
        bool ok = true;
        for (int x = 0; x < 2; x++) {
          for (int y = 0; y < 3; y++)
            if (tmp[x][y] > cap[x][y]) {
              ok = false;
              break;
            }
          if (!ok) break;
        }
        if (!ok) continue;
        res[0] = min(type[0],
                     min(cap[0][0] - tmp[0][0],
                         min(cap[0][1] - tmp[0][1], cap[0][2] - tmp[0][2])));
        if (type[0] - res[0] >
            min(cap[1][0] - tmp[1][0],
                min(cap[1][1] - tmp[1][1], cap[1][2] - tmp[1][2])))
          continue;
        res[1] = i;
        res[2] = j;
        res[4] = k;
        for (int x = 0; x < 3; x++) tmp[0][x] += res[0];
        res[3] = min(type[3], cap[0][0] - tmp[0][0]);
        res[5] = min(type[5], cap[0][1] - tmp[0][1]);
        res[6] = min(type[6], cap[0][2] - tmp[0][2]);
        for (int x = 0; x < 7; x++) printf("%d ", res[x]);
        puts("");
        return;
      }
  puts("-1");
}
int main() {
  int T;
  for (scanf("%d", &T); T; T--) ikun();
  return 0;
}
