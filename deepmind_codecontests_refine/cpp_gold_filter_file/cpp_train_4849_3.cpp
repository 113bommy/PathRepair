#include <bits/stdc++.h>
using namespace std;
string temp;
char s[105][205];
int life[105][105];
string names[105];
map<string, int> mp;
int ans[105];
int main() {
  int t, n, m, tempflag, l;
  int wtf, gg;
  bool flag;
  cin >> t;
  while (t--) {
    mp.clear();
    scanf("%d", &n);
    for (int i = 1; i <= n; i++) {
      cin >> names[i];
      mp[names[i]] = i;
    }
    flag = 0;
    memset(ans, 0, sizeof(ans));
    memset(life, 0, sizeof(life));
    scanf("%d", &m);
    getchar();
    for (int i = 1; i <= m; i++) {
      cin.getline(s[i], 200);
      if (s[i][0] == '?') {
        l = strlen(s[i]);
        for (int j = 2; j <= l; j++) {
          if ((s[i][j] >= '0' && s[i][j] <= '9') ||
              (s[i][j] >= 'a' && s[i][j] <= 'z') ||
              (s[i][j] >= 'A' && s[i][j] <= 'Z'))
            temp += s[i][j];
          else {
            life[i][mp[temp]] = 1;
            temp.clear();
          }
        }
        wtf = 0;
        for (int j = 1; j <= n; j++) {
          if (life[i][j])
            life[i][j] = 0;
          else {
            if (ans[i - 1] != j) {
              life[i][j] = 1;
              wtf++;
              gg = j;
            }
          }
        }
        if (wtf == 1) ans[i] = gg;
      } else {
        for (int j = 0; s[i][j] != ':'; j++) temp += s[i][j];
        ans[i] = mp[temp];
        if (ans[i - 1] == ans[i])
          ans[i] = 0;
        else
          life[i][ans[i]] = 1;
        temp.clear();
      }
    }
    for (int i = m; i; i--) {
      if (!ans[i]) {
        for (int j = 1; j <= n; j++) {
          if (life[i][j] == 1) {
            ans[i] = j;
            break;
          }
        }
        if (!ans[i]) flag = 1;
      }
      life[i - 1][ans[i]] = 0;
    }
    if (flag)
      printf("Impossible\n");
    else {
      for (int i = 1; i <= m; i++) {
        if (s[i][0] == '?') {
          cout << names[ans[i]];
          printf("%s\n", s[i] + 1);
        } else
          printf("%s\n", s[i]);
      }
    }
  }
  return 0;
}
