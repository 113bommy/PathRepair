#include <bits/stdc++.h>
using namespace std;
struct func {
  int numt;
  int type[5];
};
struct templ {
  int num;
  func f[1500];
};
templ fff[1002];
func g_funtmp;
int g_now;
map<string, int> mapind;
map<string, int> can;
map<string, int> mapvari;
int g_ind;
char ss[20000];
char funname[2000], sztmpv[2000], vari[2000];
int g_type[5], g_tmpnum;
int getfirst(char *name) {
  int i = 0;
  while (name[i] == ' ') i++;
  return i + 4;
}
void getfunname(char *sz, int iflg) {
  int i = 0;
  int ty[5], tmpind, tt;
  while (sz[i] == ' ') i++;
  int j;
  for (j = 0; sz[i] != '(' && sz[i] != ' '; i++) {
    funname[j++] = sz[i];
  }
  funname[j] = 0;
  while (sz[i] == ' ' || sz[i] == '(') i++;
  if (!mapind[funname]) {
    if (iflg == 1)
      mapind[funname] = ++g_ind;
    else {
      g_now = -1;
      return;
    }
  }
  g_now = mapind[funname];
  memset(g_type, 0, sizeof(g_type));
  g_tmpnum = 0;
  int flg = 1;
  int funnum = fff[g_now].num;
  for (j = 0; sz[i]; i++) {
    if (sz[i] == ' ') continue;
    if (sz[i] == ',' || sz[i] == ')') {
      sztmpv[j] = 0;
      if (iflg == 1) {
        g_type[g_tmpnum++] = can[sztmpv];
      } else
        g_type[g_tmpnum++] = mapvari[sztmpv];
      if (sz[i] == ')') break;
      j = 0;
    } else {
      sztmpv[j++] = sz[i];
    }
  }
}
int main() {
  int n, m, t, itmp;
  can["int"] = 1;
  can["double"] = 2;
  can["string"] = 3;
  can["T"] = 4;
  scanf("%d\n", &n);
  int i, j, ind, tt;
  for (tt = 0; tt < n; tt++) {
    gets(ss);
    j = getfirst(ss);
    getfunname(ss + j, 1);
    memcpy(fff[g_now].f[fff[g_now].num].type, g_type, sizeof(g_type));
    fff[g_now].f[fff[g_now].num].numt = g_tmpnum;
    fff[g_now].num++;
  }
  scanf("%d\n", &m);
  for (tt = 0; tt < m; tt++) {
    i = j = 0;
    gets(ss);
    while (ss[j] == ' ') j++;
    while (ss[j] != ' ') sztmpv[i++] = ss[j++];
    sztmpv[i] = 0;
    i = 0;
    while (ss[j] == ' ') j++;
    while (ss[j] != ' ') vari[i++] = ss[j++];
    vari[i] = 0;
    mapvari[vari] = can[sztmpv];
  }
  scanf("%d\n", &t);
  int ans, flg;
  for (tt = 0; tt < t; tt++) {
    gets(ss);
    getfunname(ss, 0);
    if (g_now == -1) {
      puts("0");
      continue;
    }
    ind = mapind[funname];
    ans = 0;
    for (i = 0; i < fff[ind].num; i++) {
      if (g_tmpnum == fff[ind].f[i].numt) {
        flg = 1;
        for (j = 0; j < g_tmpnum; j++) {
          if (g_type[j] & 0x4 || fff[ind].f[i].type[j] & 0x4 ||
              g_type[j] == fff[ind].f[i].type[j])
            continue;
          flg = 0;
          break;
        }
        if (flg) ans++;
      }
    }
    printf("%d\n", ans);
  }
}
