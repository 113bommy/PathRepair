#include <bits/stdc++.h>
#pragma warning(disable : 4996)
int n, m;
long long p;
long long a[20000];
long long b[200000];
long long c[20000];
long long so[100][2];
int soi;
int stat[100];
long long su = 1;
long long pi[2000];
struct YAKSU {
  long long su;
  int jisu[100];
} yak[2000];
int yaki;
int antiyak[2000];
int ryak[2000];
long long gcd(long long x, long long y) { return x == 0 ? y : gcd(y % x, x); }
void findso(long long x) {
  int i;
  for (i = 2; i <= sqrt((long double)x); i++) {
    if (x % i == 0) {
      so[soi][0] = i;
      while (x % i == 0) {
        x /= i;
        so[soi][1]++;
      }
      soi++;
      findso(x);
      return;
    }
  }
  so[soi][0] = x;
  so[soi++][1] = 1;
}
int fastpow(long long x, long long y) {
  int bin[40] = {
      0,
  };
  int bini = 0;
  int i;
  while (y > 0) {
    bin[bini++] = y % 2;
    y /= 2;
  }
  long long dab = 1;
  for (i = 0; i < bini; i++) {
    if (bin[i]) {
      dab *= x;
      dab %= p;
    }
    x = x * x;
    x %= p;
  }
  return dab;
}
void dfs(int now) {
  int i;
  if (now == soi) {
    yak[yaki].su = su;
    for (i = 0; i < soi; i++) {
      yak[yaki].jisu[i] = stat[i];
    }
    yaki++;
    return;
  }
  long long tsu = su;
  for (i = 0; i <= so[now][1]; i++) {
    stat[now] = i;
    dfs(now + 1);
    su *= so[now][0];
  }
  su = tsu;
}
int main() {
  int i, j, k;
  scanf("%d%d%I64d", &n, &m, &p);
  for (i = 0; i < n; i++) scanf("%I64d", &a[i]);
  for (i = 0; i < m; i++) scanf("%I64d", &b[i]);
  long long g = p - 1;
  for (i = 0; i < m; i++) g = gcd(g, b[i]);
  findso(p - 1);
  for (i = 0; i < n; i++) {
    a[i] = fastpow(a[i], g);
  }
  dfs(0);
  for (i = 0; i < yaki; i++) {
    for (j = i + 1; j < yaki; j++) {
      if (yak[i].su * yak[j].su == p - 1) {
        antiyak[i] = j;
        antiyak[j] = i;
      }
    }
  }
  for (i = 0; i < n; i++) {
    long long min = 0x7fffffff;
    int mini;
    for (j = 0; j < yaki; j++) {
      if (fastpow(a[i], yak[j].su) == 1) {
        if (min > yak[j].su) {
          min = yak[j].su, mini = j;
        }
      }
    }
    ryak[antiyak[mini]] = 1;
  }
  for (i = 0; i < yaki; i++) {
    if (!ryak[i]) continue;
    for (j = 0; j < yaki; j++) {
      if (ryak[j]) continue;
      int flag = 0;
      for (k = 0; k < soi; k++) {
        if (yak[j].jisu[k] < yak[i].jisu[k]) {
          flag = 1;
          break;
        }
      }
      if (flag == 0) ryak[j] = 1;
    }
  }
  for (i = 0; i < yaki; i++) {
    int anti[20] = {
        0,
    };
    for (j = 0; j < soi; j++) {
      anti[j] = so[j][1] - yak[i].jisu[j];
    }
    long long dab = 1;
    for (j = 0; j < soi; j++) {
      if (anti[j] == 0) continue;
      for (k = 0; k < anti[j] - 1; k++) dab *= so[j][0];
      dab *= so[j][0] - 1;
    }
    pi[i] = dab;
  }
  long long rdab = 0;
  for (i = 0; i < yaki; i++) {
    if (ryak[i]) rdab += pi[i];
  }
  printf("%I64d", rdab);
  return 0;
}
