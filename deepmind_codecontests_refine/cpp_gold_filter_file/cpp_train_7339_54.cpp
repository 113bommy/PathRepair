#include <bits/stdc++.h>
using namespace std;
const int maxn = 100005;
const int mod = 2015;
char mp[10][10];
int main() {
  while (scanf("%s", mp[0]) != EOF) {
    for (int i = 1; i < 8; i++) scanf("%s", mp[i]);
    int res1 = 100, res2 = 100;
    for (int i = 0; i < 8; i++) {
      for (int j = 0; j < 8; j++) {
        if (mp[j][i] == 'B') break;
        if (mp[j][i] == 'W') res1 = min(j, res1);
      }
      for (int j = 7; j >= 0; j--) {
        if (mp[j][i] == 'W') break;
        if (mp[j][i] == 'B') res2 = min(7 - j, res2);
      }
    }
    printf("%c\n", res1 > res2 ? 'B' : 'A');
  }
  return 0;
}
