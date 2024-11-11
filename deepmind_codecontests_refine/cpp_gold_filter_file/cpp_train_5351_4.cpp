#include <bits/stdc++.h>
using namespace std;
int main() {
  char s[12][12];
  int r, c;
  scanf("%d%d", &r, &c);
  int ans = r * c, cpt = 0;
  for (int j = 0; j < r; j++)
    for (int i = 0; i < c; i++) cin >> s[j][i];
  int cc = 0, rr = 0;
  for (int i = 0; i < c; i++)
    for (int j = 0; j < r; j++)
      if (s[j][i] == 'S') {
        rr++;
        break;
      }
  for (int j = 0; j < r; j++)
    for (int i = 0; i < c; i++)
      if (s[j][i] == 'S') {
        cc++;
        break;
      }
  cpt = rr * cc;
  cout << ans - cpt;
  return 0;
}
