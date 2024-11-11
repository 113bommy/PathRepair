#include <bits/stdc++.h>
using namespace std;
const int N = 2000 + 10;
int f[N][N];
int ch[N * 200][26], sz, ret;
int num, l[11], r[11];
char s[N], p[11][N];
int vis[N], cnt[N], key[N * 200];
void getfail(char *p, int f[]) {
  int m = strlen(p);
  f[0] = 0;
  f[1] = 0;
  for (int i = 1; i < m; i++) {
    int j = f[i];
    while (j && p[i] != p[j]) j = f[j];
    f[i + 1] = p[i] == p[j] ? j + 1 : 0;
  }
}
void init() {
  int len = strlen(s);
  char *q = s;
  for (int i = 0; i < len; i++) {
    getfail(q, f[i]);
    q++;
  }
  memset(ch[0], 0, sizeof(ch[0]));
  memset(key, 0, sizeof(key));
  sz = 1;
}
void insert(char *s) {
  int m = strlen(s), rt = 0;
  for (int i = 0; i < m; i++) {
    int c = s[i] - 'a';
    if (ch[rt][c] == 0) {
      memset(ch[sz], 0, sizeof(ch[sz]));
      ch[rt][c] = sz;
      sz++;
    }
    rt = ch[rt][c];
  }
  if (key[rt] == 0) {
    ret++;
    key[rt] = 1;
  }
}
int find(char *T, char *p, int f[]) {
  int j = 0;
  int n = strlen(T);
  int m = strlen(p);
  for (int i = 0; i < n; i++) {
    while (j && T[i] != p[j]) j = f[j];
    if (T[i] == p[j]) j++;
    cnt[j]++;
  }
}
void work() {
  char *q = s;
  int len = strlen(s);
  for (int i = 0; i < len; i++) {
    memset(vis, 0, sizeof(vis));
    for (int j = 0; j < num; j++) {
      memset(cnt, 0, sizeof(cnt));
      find(p[j], q, f[i]);
      for (int k = 1; k <= len - i; k++) {
        if (cnt[k] < l[j] || cnt[k] > r[j]) vis[k] = 1;
      }
    }
    char ss[N];
    for (int j = 1; j <= len - i; j++) {
      ss[j - 1] = s[i + j - 1];
      if (vis[j] == 0) {
        ss[j] = '\0';
        insert(ss);
      }
    }
    q++;
  }
}
int main() {
  while (~scanf("%s", s)) {
    scanf("%d", &num);
    memset(vis, 0, sizeof(vis));
    init();
    for (int i = 0; i < num; i++) {
      scanf("%s", p[i]);
      scanf("%d%d", &l[i], &r[i]);
    }
    ret = 0;
    work();
    cout << ret << endl;
  }
  return 0;
}
