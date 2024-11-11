#include <bits/stdc++.h>
long long n, k, E7 = 1e7, E6 = 1e6;
int w[10000051], ls[10000051], tot, cnt[2][10][1000051];
int a[2000051], lsa[2000051], ta;
bool check(long long x) {
  long long t = x % 10;
  x /= 10;
  int ic = 0;
  for (; x;) {
    long long s = x % 10;
    if (s == t) return 0;
    if (s > t) {
      if (ic == -1) return 0;
      ic = -1;
    }
    if (s < t) {
      if (ic == 1) return 0;
      ic = 1;
    }
    t = s, x /= 10;
  }
  return 1;
}
void dfs(int dep = 1, int exp = 0, int typ = 1, int lsc = 0, int lst = -1) {
  if (dep == E7) {
    w[++tot] = exp, ls[exp] = lsc, cnt[typ][exp / E6][(n - exp % n) % n]++;
    return;
  }
  if (lst && exp) a[++ta] = exp, lsa[exp] = lsc;
  if (dep == 10) {
    for (register int i = 0; i < lst; i++) dfs(100, exp + dep * i, 1, 0, i);
    for (register int i = lst + 1; i < 10; i++)
      dfs(100, exp + dep * i, 0, 1, i);
    return;
  }
  if (typ == 1)
    for (register int i = lst + 1; i < 10; i++)
      dfs(dep * 10, exp + dep * i, !typ, lsc, i);
  else
    for (register int i = 0; i < lst; i++)
      dfs(dep * 10, exp + dep * i, !typ, lsc, i);
}
void scan(long long Bas, int k) {
  register int i;
  for (i = 0; i < 1e7; i++)
    if ((Bas + i) % n == 0) {
      if (check(Bas + i)) k--;
      if (!k) {
        printf("%lld\n", Bas + i);
        return;
      }
    }
}
void runbf() {
  for (register long long i = n; i <= 1e14; i += n)
    if (check(i)) {
      k--;
      if (!k) {
        printf("%lld\n", i);
        return;
      }
    }
  puts("-1");
}
int main() {
  scanf("%lld%lld", &n, &k);
  if (n > 1e6) return runbf(), 0;
  dfs();
  register int i, ii;
  std::sort(a + 1, a + ta + 1);
  std::sort(w + 1, w + tot + 1);
  for (i = 1; i <= ta; i++)
    if (a[i] % n == 0) {
      k--;
      if (!k) {
        printf("%d\n", a[i]);
        return 0;
      }
    }
  for (i = 1; i <= tot; i++)
    if (w[i] > 1e6 && w[i] % n == 0) {
      k--;
      if (!k) {
        printf("%d\n", w[i]);
        return 0;
      }
    }
  for (i = 1; i <= ta; i++) {
    long long t = a[i] * E7 % n;
    if (a[i] < 10) {
      int g = a[i], dk = 0;
      for (ii = 0; ii < a[i]; ii++) dk += cnt[1][ii][t];
      for (ii = a[i] + 1; ii < 10; ii++) dk += cnt[0][ii][t];
      if (k > dk) {
        k -= dk;
        continue;
      }
      return scan(a[i] * E7, k), 0;
    } else {
      int g = a[i] % 10, dr = lsa[a[i]];
      int dk = 0;
      if (dr) {
        for (ii = g + 1; ii < 10; ii++) dk += cnt[0][ii][t];
      } else {
        for (ii = 0; ii < g; ii++) dk += cnt[1][ii][t];
      }
      if (k > dk) {
        k -= dk;
        continue;
      }
      return scan(a[i] * E7, k), 0;
    }
  }
  for (i = 1; i <= tot; i++)
    if (w[i] > 1e6) {
      long long t = w[i] * E7 % n, dr = ls[w[i]];
      int dk = 0, g = w[i] % 10;
      if (dr) {
        for (ii = g + 1; ii < 10; ii++) dk += cnt[0][ii][t];
      } else {
        for (ii = 0; ii < g; ii++) dk += cnt[1][ii][t];
      }
      if (k > dk) {
        k -= dk;
        continue;
      }
      return scan(w[i] * E7, k), 0;
    }
  puts("-1");
}
