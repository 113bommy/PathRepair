#include <bits/stdc++.h>
using namespace std;
int sx, sy, ex, ey;
char str[3];
vector<string> ans;
int main() {
  scanf("%s", str);
  sx = (int)(str[0] - 'a'), sy = (int)(str[1] - '1');
  scanf("%s", str);
  ex = (int)(str[0] - 'a'), ey = (int)(str[1] - '1');
  while (sx != ex || sy != ey) {
    if (sx == ex) {
      if (sy < ey)
        ans.push_back("D"), sy++;
      else
        ans.push_back("U"), sy--;
    } else if (sy == ey) {
      if (sx < ex)
        ans.push_back("R"), sx++;
      else
        ans.push_back("L"), sx--;
    } else {
      if (sx < ex) {
        if (sy < ey)
          ans.push_back("RU"), sy++;
        else
          ans.push_back("RD"), sy--;
        sx++;
      } else {
        if (sy < ey)
          ans.push_back("LU"), sy++;
        else
          ans.push_back("LD"), sy--;
        sx--;
      }
    }
  }
  printf("%d\n", ans.size());
  for (int i = 0; i < ans.size(); ++i) cout << ans[i] << endl;
  return 0;
}
