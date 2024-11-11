#include <bits/stdc++.h>
using namespace std;
const int MAXN = 1e6;
const int MOD = 1e9 + 7;
int n, m, y[MAXN + 3], p;
char s[MAXN + 3], mark[MAXN + 3];
int total;
void rec(int pos, int i) {
  if (pos == n) {
    return;
  }
  if (i == m) {
    total++;
    mark[pos] = 1;
    rec(pos + 1, i);
  } else if (pos < y[i]) {
    total++;
    mark[pos] = 1;
    rec(pos + 1, i);
  } else if (y[i] <= pos && pos <= y[i] + p - 1) {
    rec(pos + 1, i);
  } else {
    rec(pos, i + 1);
  }
}
int modpow(int a, int n) {
  int ret = 1;
  while (n > 0) {
    if (n % 2 == 0) {
      a = ((long long)a * a) % MOD;
      n /= 2;
    } else {
      ret = ((long long)ret * a) % MOD;
      n--;
    }
  }
  return ret;
}
char s1[MAXN + 3], s2[MAXN + 3];
void build1(int pos, int i) {
  if (pos == n) {
    return;
  }
  if (i == m) {
    s1[pos] = '?';
    build1(pos + 1, i);
    return;
  }
  if (pos < y[i]) {
    s1[pos] = '?';
    build1(pos + 1, i);
    return;
  }
  if (y[i] <= pos && pos <= y[i] + p - 1) {
    s1[pos] = s[pos - y[i]];
    build1(pos + 1, i);
    return;
  }
  if (y[i] + p - 1 < pos) {
    build1(pos, i + 1);
    return;
  }
}
void build2(int pos, int i) {
  if (pos == n) {
    return;
  }
  if (i == m) {
    s2[pos] = '?';
    build2(pos + 1, i);
    return;
  }
  if (pos < y[i]) {
    s2[pos] = '?';
    build2(pos + 1, i);
    return;
  }
  if (i + 1 < m && y[i + 1] <= pos && pos <= y[i + 1] + p - 1) {
    build2(pos, i + 1);
    return;
  }
  if (y[i] <= pos && pos <= y[i] + p - 1) {
    s2[pos] = s[pos - y[i]];
    build2(pos + 1, i);
    return;
  }
  if (y[i] + p - 1 < pos) {
    build2(pos, i + 1);
    return;
  }
}
int main(int argc, char* argv[]) {
  memset(y, 0x3F3F3F3F, sizeof(y));
  scanf("%d %d\n%s", &n, &m, s);
  for (int i = 0; i < m; i++) {
    scanf("%d", y + i);
    y[i]--;
  }
  p = strlen(s);
  rec(0, 0);
  build1(0, 0);
  build2(0, 0);
  bool bad = strcmp(s1, s2) != 0;
  if (bad) {
    printf("0\n");
  } else {
    int ans = modpow(26, total);
    printf("%d\n", ans);
  }
  return 0;
}
