#include <bits/stdc++.h>
using namespace std;
struct aaa {
  int dmg, pow, num;
  int ussec;
  bool used;
};
int n;
aaa f[1002];
int maxi, reg, php;
bool comp(const aaa v1, const aaa v2) {
  if (v1.used == v2.used) {
    return v1.ussec < v2.ussec;
  } else
    return v1.used > v2.used;
}
int main() {
  scanf("%d %d %d", &n, &maxi, &reg);
  int g = -1;
  for (int i = 0; i < n; i++) {
    scanf("%d %d", &f[i].pow, &f[i].dmg);
    f[i].num = i + 1;
    if (f[i].pow == 100 && (g == -1 || f[i].dmg > f[g].dmg)) g = i;
  }
  int sec = 0;
  if (g == -1) {
    printf("NO\n");
    return 0;
  }
  php = maxi;
  reg -= f[g].dmg;
  f[g].used = true;
  while (sec < 1000000) {
    php = min(maxi, php + reg);
    if (php <= 0) {
      printf("YES\n");
      printf("%d", sec + 1);
      sort(f, f + n, comp);
      int us = 0;
      while (f[us].used == true) us++;
      printf(" %d\n", us);
      for (int i = 0; i < us; i++) printf("%d %d\n", f[i].ussec, f[i].num);
      return 0;
    }
    int tmp = -1;
    double pp = php * 100.0 / (double)maxi;
    for (int i = 0; i < n; i++) {
      if (f[i].used == false) {
        if ((double)f[i].pow >= pp) {
          if (tmp == -1 || f[i].dmg > f[tmp].dmg) tmp = i;
        }
      }
    }
    if (tmp == -1 && reg >= 0) {
      printf("NO\n");
      return 0;
    }
    if (tmp != -1) {
      reg -= f[tmp].dmg;
      f[tmp].used = true;
      f[tmp].ussec = sec + 1;
    }
    sec++;
  }
  return 0;
}
