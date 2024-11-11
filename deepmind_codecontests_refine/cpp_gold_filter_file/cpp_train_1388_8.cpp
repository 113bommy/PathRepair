#include <bits/stdc++.h>
using namespace std;
const int maxp = 35;
const int maxn = 10005;
const int INF = 1 << 30;
long long a[maxn];
int pn[maxp], ps;
int mod[maxp], ms;
int ord[maxp];
int lim[maxp];
int n, m;
void init() {
  scanf("%d", &n);
  for (int i = 0; i < n; i++) scanf("%I64d", &a[i]);
}
int pop[20][20];
vector<int> f[5][17];
void work() {
  ps = 1;
  pn[0] = 2;
  for (int i = 3; i < 100; i++) {
    bool flag = 1;
    for (int j = 0; j < ps && flag; j++)
      if (i % pn[j] == 0) flag = 0;
    if (flag) pn[ps++] = i;
  }
  ms = 0;
  for (int i = 0; i < ps;) {
    mod[ms] = 1;
    while (i < ps && INF / pn[i] >= mod[ms]) ord[i] = ms, mod[ms] *= pn[i++];
    ms++;
  }
  int cnt = 0;
  for (int i = 2; i <= 16; i++) {
    int cur = 1;
    pop[i + 1][0] = 1;
    for (int j = 1; cur < 10000; j++)
      cur *= i, lim[i] = j, pop[i + 1][j] = pop[i + 1][j - 1] * (i + 1);
    for (int j = 0; j < ms; j++) {
      f[j][i].resize(pop[i + 1][lim[i]], -1);
    }
  }
}
char st[maxp];
int len, pos;
int getdit(char ch) {
  if (ch >= 'A' && ch <= 'Z') return ch - 'A' + 11;
  if (ch >= '0' && ch <= '9') return ch - '0' + 1;
  return 0;
}
int calc(int t, int d, int pos, int hash, int sum) {
  if (f[t][d][hash] != -1) return f[t][d][hash];
  if (pos > len || sum >= n) {
    return sum < n ? (a[sum] % mod[t]) : 1;
  }
  int &ret = f[t][d][hash];
  if (st[pos] != '?') {
    ret = calc(t, d, pos + 1, hash, sum * d + getdit(st[pos]) - 1);
  } else {
    ret = 1;
    for (int cur = 0; cur < d; cur++)
      ret = (long long)ret *
            calc(t, d, pos + 1, hash + (cur + 1) * pop[d + 1][len - pos],
                 sum * d + cur) %
            mod[t];
  }
  return ret;
}
void print() {
  scanf("%d", &m);
  long long c;
  int d;
  for (int t = 0; t < m; t++) {
    scanf("%d%s%I64d", &d, st + 1, &c);
    len = strlen(st + 1), pos = 0;
    while (len - pos > lim[d] && (st[pos + 1] == '?' || st[pos + 1] == '0'))
      pos++;
    if (len - pos > lim[d]) {
      bool flag = 1;
      for (int i = 0; i < ps && flag; i++)
        if (c % pn[i] == 0) {
          printf("%d\n", pn[i]);
          flag = 0;
        }
      if (flag) puts("-1");
      continue;
    }
    int hash = 0;
    for (int i = len - pos; i < lim[d]; i++) hash = hash * (d + 1) + 1;
    for (int i = pos + 1; i <= len; i++) hash = hash * (d + 1) + getdit(st[i]);
    bool flag = 1;
    for (int i = 0; i < ps && flag; i++) {
      long long tmp = calc(ord[i], d, pos + 1, hash, 0) + c;
      if (tmp % pn[i] == 0) {
        printf("%d\n", pn[i]);
        flag = 0;
      }
    }
    if (flag) puts("-1");
  }
}
int main() {
  init();
  work();
  print();
  return 0;
}
