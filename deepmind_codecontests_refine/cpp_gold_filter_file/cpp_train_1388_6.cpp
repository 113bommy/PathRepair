#include <bits/stdc++.h>
using namespace std;
using namespace rel_ops;
const double PI = acos((double)-1);
int ts, ts2, ts3, ts4;
int n, m;
long long gcd(long long x, long long y) {
  long long t;
  for (; y != 0;) {
    t = x % y;
    x = y;
    y = t;
  }
  return x;
}
double sqr(double x) { return x * x; }
long long *f[6][17], zs[105], zs2, md[6];
long long D, C;
long long a[10005], sl;
char s[100];
int sosuu(int x) {
  for (int i = 2; i * i <= x; i++)
    if (x % i == 0) return 0;
  return 1;
}
int b[105], II;
long long(*g), nmd;
int XX;
long long work(int k) {
  if (II == 5) ts = 0;
  long long i, j, l, t1, t2, t3, t4, t5, t6, t7, t8, t9, t, nw;
  t1 = 0;
  for (i = sl; i >= 1; i--) {
    t1 = t1 * (D) + (b[i] == -1 ? 0 : b[i]);
  }
  if (t1 >= n) return -1;
  long long num2 = t1;
  t1 = 0;
  for (i = sl; i >= 1; i--) {
    t1 = t1 * (D + 1) + (b[i] == -1 ? D : b[i]);
  }
  long long num = t1;
  if (g[num] != -1) {
    return num;
  }
  g[num] = 1;
  for (i = k; i <= sl; i++) {
    if (b[i] != -1) continue;
    for (j = 0; j < D; j++) {
      b[i] = j;
      t1 = work(k + 1);
      if (t1 != -1) {
        g[num] = g[num] * g[t1] % nmd;
      }
    }
    b[i] = -1;
    return num;
  }
  g[num] = a[num2 + 1] % nmd;
  return num;
}
int main() {
  long long i, j, k, l, t1, t2, t3, t4, t5, t6, t7, t8, t9, t, nw;
  int tt1, tt2, tt3, tt4;
  double u1, u2, u3, u4, u5, u6, u7, u8, u9;
  char c1, c2, c3;
  srand((unsigned)time(0));
  (memset((f), -1, sizeof((f))));
  ios::sync_with_stdio(0);
  cin >> n;
  for (i = 1; i <= n; i++) cin >> a[i];
  for (i = 1; i <= 5; i++)
    for (j = 2; j <= 16; j++) {
      if (j == 16) ts = 0;
      for (t1 = 1, k = 1; t1 <= n; t1 *= j, k *= j + 1)
        ;
      f[i][j] = new long long[k + 5];
      fill(f[i][j], f[i][j] + k + 5, -1);
    }
  cin >> m;
  for (i = 2; i <= 100; i++)
    if (sosuu(i)) {
      zs[++zs2] = i;
    }
  t1 = 1;
  t2 = 1;
  for (i = 1; i <= zs2 + 1; i++) {
    zs[zs2 + 1] = 1;
    if (i == zs2 + 1 || t1 * zs[i] > 1000000000) {
      md[t2] = t1;
      t1 = 1;
      t2++;
    }
    t1 *= zs[i];
  }
  for (int x = 1; x <= m; x++) {
    XX = x;
    cin >> D >> s + 1 >> C;
    sl = strlen(s + 1);
    (memset((b), 0, sizeof((b))));
    for (i = 1; i <= sl; i++) {
      b[i] = s[sl - i + 1];
      b[i] = b[i] == '?' ? -1 : b[i] >= 'A' ? b[i] - 65 + 10 : b[i] - 48;
    }
    if (x == 2) ts = 0;
    for (t1 = 1, k = 0; t1 <= n; t1 *= D, k++)
      ;
    int sl2 = sl;
    sl = min(sl, k);
    for (j = k + 1; j <= sl2; j++)
      if (b[j] != -1 && b[j] != 0) break;
    int flag = 0;
    if (j <= sl2) {
      flag = 1;
    }
    for (i = 1; i <= 5; i++) {
      II = i;
      nmd = md[i];
      g = f[i][D];
      t2 = work(1);
      if (t2 >= 0 && !flag)
        t1 = (g[t2] + C) % md[i];
      else
        t1 = (1 + C) % md[i];
      for (j = 1; j <= zs2; j++)
        if (md[i] % zs[j] == 0 && t1 % zs[j] == 0) {
          break;
        }
      if (j <= zs2) break;
    }
    if (j <= zs2)
      cout << zs[j] << endl;
    else
      cout << -1 << endl;
  }
  return 0;
}
