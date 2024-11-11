#include <bits/stdc++.h>
using namespace std;
const int MAXSIZE = 30000020;
int bufpos;
char buf[MAXSIZE];
void init() {
  buf[fread(buf, 1, MAXSIZE, stdin)] = '\0';
  bufpos = 0;
}
int readint() {
  int val = 0;
  for (; !isdigit(buf[bufpos]); bufpos++)
    ;
  for (; isdigit(buf[bufpos]); bufpos++) val = val * 10 + buf[bufpos] - '0';
  return val;
}
char readchar() {
  for (; isspace(buf[bufpos]); bufpos++)
    ;
  return buf[bufpos++];
}
int readstr(char* s) {
  int cur = 0;
  for (; isspace(buf[bufpos]); bufpos++)
    ;
  for (; !isspace(buf[bufpos]); bufpos++) s[cur++] = buf[bufpos];
  s[cur] = '\0';
  return cur;
}
int a[402][402];
bool vis[402];
vector<int> now;
vector<int> e[402];
double cnt[402];
double tmp[202];
int main() {
  init();
  int n = readint(), m = readint();
  memset(a, 0x3f, sizeof(a));
  while (m--) {
    int x = readint(), y = readint();
    a[x][y] = a[y][x] = 1;
    e[x].push_back(y);
    e[y].push_back(x);
  }
  for (int i = 1; i <= n; i++) a[i][i] = 0;
  for (int k = 1; k <= n; k++)
    for (int i = 1; i <= n; i++)
      for (int j = 1; j <= n; j++) a[i][j] = min(a[i][j], a[i][k] + a[k][j]);
  double res = 0;
  for (int i = 1; i <= n; i++) {
    double qwq = 0;
    for (int j = 0; j <= n; j++) {
      for (int k = 1; k <= n; k++)
        if (a[i][k] == j) {
          for (int o : e[k]) {
            if (!tmp[o]) now.push_back(o);
            tmp[o] += 1.0 / n / e[k].size();
          }
        }
      if (!now.size()) continue;
      double ans = 1.0 / n;
      for (int k = 1; k <= n; k++) {
        double sum = 0;
        for (int o : now) cnt[a[k][o]] = max(cnt[a[k][o]], tmp[o]);
        for (int o : now) sum += cnt[a[k][o]], cnt[a[k][o]] = 0;
        ans = max(ans, sum);
      }
      for (int o : now) tmp[o] = 0;
      now.clear();
      qwq += ans;
    }
    res = max(res, qwq);
  }
  printf("%.10f", res);
}
