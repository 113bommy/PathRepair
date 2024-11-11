#include <bits/stdc++.h>
using namespace std;
const int N = 1e6 + 10;
int n, k, tot;
char s[N];
int ch[N][26], f[N];
void insert() {
  int l = strlen(s + 1);
  int now = 0;
  for (int i = 1; i <= l; i++) {
    if (!ch[now][s[i] - 'a']) ch[now][s[i] - 'a'] = ++tot;
    now = ch[now][s[i] - 'a'];
  }
}
void dfs(int x) {
  int cnt = 0, a[5];
  memset(a, 0, sizeof(a));
  for (int i = 0; i < 26; i++) {
    if (ch[x][i]) {
      dfs(ch[x][i]);
      cnt++;
      a[f[ch[x][i]]]++;
    }
  }
  if (cnt == 0) return (void)(f[x] = 1);
  if (a[3])
    f[x] = 4;
  else if (a[1] && !a[2])
    f[x] = 2;
  else if (!a[1] && a[2])
    f[x] = 1;
  else if (a[1] && a[2])
    f[x] = 4;
  else if ((a[1] + a[2] + a[3] == 0) && a[4])
    f[x] = 3;
  else if ((a[1] + a[2] + a[4] == 0) && a[3])
    f[x] = 4;
}
int main() {
  scanf("%d%d", &n, &k);
  for (int i = 1; i <= n; i++) {
    scanf("%s", s + 1);
    insert();
  }
  dfs(0);
  int a[5];
  memset(a, 0, sizeof(a));
  for (int i = 0; i < 26; i++) {
    if (ch[0][i]) a[f[ch[0][i]]]++;
  }
  if (a[3])
    f[0] = 3;
  else if (a[1] && !a[2])
    f[0] = 1;
  else if (a[2] && !a[1])
    f[0] = 2;
  else if (a[1] && a[2])
    f[0] = 3;
  else if ((a[1] + a[2] + a[3] == 0) && a[4])
    f[0] = 4;
  if (f[0] == 3)
    puts("First");
  else if (f[0] == 4)
    puts("Second");
  else if (f[0] == 2)
    puts("Second");
  else {
    if (k & 1)
      puts("First");
    else
      puts("Second");
  }
  return 0;
}
