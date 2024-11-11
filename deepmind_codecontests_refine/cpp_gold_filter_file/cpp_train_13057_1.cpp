#include <bits/stdc++.h>
using namespace std;
const int N = 110;
int f[N];
string st[6] = {"1x12", "2x6", "3x4", "4x3", "6x2", "12x1"};
int g[12];
int main() {
  int t, i, j;
  string ch;
  scanf("%d", &t);
  while (t--) {
    memset(f, 0, sizeof(f));
    memset(g, 0, sizeof(g));
    cin >> ch;
    int sum = 0;
    for (i = 0; i < ch.size(); i++)
      if (ch[i] == 'X') {
        f[i + 1] = 1;
        sum++;
      }
    if (sum == 0) {
      printf("0\n");
      continue;
    }
    g[0] = 1;
    for (i = 1; i <= 6; i++)
      if (f[i] + f[i + 6] == 2) g[1] = 2;
    for (i = 1; i <= 4; i++)
      if (f[i] + f[i + 4] + f[i + 8] == 3) g[2] = 3;
    for (i = 1; i <= 3; i++)
      if (f[i] + f[i + 3] + f[i + 6] + f[i + 9] == 4) g[3] = 4;
    for (i = 1; i <= 2; i++)
      if (f[i] + f[i + 2] + f[i + 4] + f[i + 6] + f[i + 8] + f[i + 10] == 6)
        g[4] = 5;
    if (sum == 12) g[5] = 6;
    int ans = 0;
    for (i = 0; i < 6; i++)
      if (g[i]) ans++;
    cout << ans << " ";
    for (i = 0; i < 6; i++)
      if (g[i]) cout << st[g[i] - 1] << " ";
    cout << endl;
  }
}
