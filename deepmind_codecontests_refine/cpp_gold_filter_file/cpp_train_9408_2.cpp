#include <bits/stdc++.h>
long long int n, mod;
typedef struct {
  long long int x, y;
} ele;
int cmp(ele a, ele b) { return a.x < b.x || a.x == b.x && a.y < b.y; }
ele e[1000514];
void shuru() {
  scanf("%I64d", &n);
  for (int i = 0; i < n; i++) {
    scanf("%I64d", &e[i].x);
    e[i].y = i + 1;
  }
  for (int i = 0; i < n; i++) {
    scanf("%I64d", &e[i + n].x);
    e[i + n].y = i + 1;
  }
  std::sort(e, e + n + n, cmp);
  scanf("%I64d", &mod);
}
long long int f[1000514];
void truli() {
  long long int ans = 1;
  f[0] = 1;
  for (long long int i = 0; i < n + n;) {
    long long int j = i, cnt = 0, two = 0;
    for (; j < n + n && e[j].x == e[i].x; j++) {
      if (j > i && e[j].y == e[j - 1].y) two++;
      cnt++;
    }
    long long int tans = 1;
    for (long long int k = 1; k <= cnt; k++) {
      long long int tmp = k;
      for (; two && tmp % 2 == 0; two--, tmp /= 2)
        ;
      tans = tans * tmp % mod;
    }
    ans = ans * tans % mod;
    i = j;
  }
  printf("%I64d\n", ans);
}
int main() {
  shuru();
  truli();
  return 0;
}
