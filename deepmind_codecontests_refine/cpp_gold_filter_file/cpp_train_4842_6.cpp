#include <bits/stdc++.h>
using namespace std;
int n;
char a[1000];
int mp[105][150];
int jishu[105][5];
int flag;
int main() {
  scanf("%d", &n);
  memset(mp, 0, sizeof(mp));
  getchar();
  for (int i = 1; i <= n; i++) {
    memset(a, 0, sizeof(a));
    gets(a);
    flag = 0;
    for (unsigned int j = 0; j < strlen(a); j++) {
      if (mp[i][a[j]] == 0) {
        jishu[i][flag] = a[j];
        flag++;
      }
      mp[i][a[j]]++;
      if (flag > 2) {
        memset(mp[i], 0, sizeof(mp[i]));
        memset(jishu[i], 0, sizeof(jishu[i]));
        break;
      }
    }
  }
  int re = 0;
  int linshi = 0;
  for (int j = 'a'; j <= 'z'; j++)
    for (int k = 'a'; k <= 'z'; k++) {
      linshi = 0;
      for (int l = 1; l <= n; l++) {
        if ((jishu[l][0] == j && jishu[l][1] == k) ||
            (jishu[l][0] == k && jishu[l][1] == j)) {
          linshi += (mp[l][j] + mp[l][k]);
        } else {
          if (jishu[l][1] < 97 || jishu[l][1] > 123) {
            if (jishu[l][0] == j) {
              linshi += mp[l][j];
            }
            if (jishu[l][0] == k && j != k) {
              linshi += mp[l][k];
            }
          }
        }
      }
      re = max(re, linshi);
    }
  cout << re << endl;
  return 0;
}
