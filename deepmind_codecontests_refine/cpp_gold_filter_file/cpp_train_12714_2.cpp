#include <bits/stdc++.h>
using namespace std;
long long n, m;
int check(long long x) {
  int res = 0;
  while (x) {
    int k = x % 10;
    x /= 10;
    res += k == 4 || k == 7;
  }
  return res;
}
long long cc(long long x) {
  long long res = 1, flag = 0;
  while (x) {
    int k = x % 10;
    if (k != 9) {
      if (k == 3 || k == 6) {
        if (flag > 3) return res - 10000;
        return 0;
      } else
        return 0;
    }
    ++flag;
    res *= 10;
    x /= 10;
  }
  return 0;
}
int main() {
  while (scanf("%I64d%I64d", &n, &m) == 2) {
    long long a = n, b = m, c = n + m - 1, d = 1, e = 0, ans = 0;
    while (b / 10 > 0) {
      e += a % 10 * d;
      a /= 10;
      c /= 10;
      b /= 10;
      d *= 10;
    }
    long long i = 0;
    int flag = 1, ff, cnt = 0, fff = 100;
    for (long long l = a; l <= c; ++l) fff = min(fff, check(l));
    if (fff < check(a + 1)) i += cc(a);
    while (flag) {
      ++i;
      int t = 1;
      if (fff < check(a + i + 1)) i += cc(a + i);
      for (long long j = a + i; j <= c + i && t; ++j) {
        if (check(j) != check(j - i)) t = 0;
      }
      if (t) {
        flag = 0;
        ff = i;
        break;
      }
      if (++cnt > 100000) break;
    }
    if (cnt < 100000)
      printf("%I64d\n", (a + ff) * d + e);
    else {
      int flag = 1;
      int k1 = a % 10, k2 = c % 10;
      a /= 10;
      c /= 10;
      if (k1 == k2 && a == 0 && c) {
        ans += d * k1;
        d *= 10;
        k1 = 0;
        k2 = c % 10;
        c /= 10;
      }
      while (k1 != k2) {
        int fff = 0;
        if (k2 < k1) k2 += 10;
        for (int i = 1; i <= 9; ++i) {
          int ff = 1;
          for (int j = k1 + i; j <= k2 + i; ++j) {
            if (check(j % 10) != check((j - i) % 10)) {
              ff = 0;
              break;
            }
          }
          if (ff) {
            fff = i;
            break;
          }
        }
        if (!fff) {
          ans += d * k1;
          d *= 10;
          k1 = a % 10;
          k2 = c % 10;
          a /= 10;
          c /= 10;
        } else {
          if (fff + k1 > 9) {
            int pre = a % 10, pc = c % 10;
            a /= 10;
            c /= 10;
            if (pre == 4 || pre == 7 || pre == 3 || pre == 6) {
              if (pre != pc)
                ans += d * k1;
              else
                ans += d * ((k1 + fff) % 10);
              k1 = pre;
              k2 = pc;
              d *= 10;
            } else {
              ans += d * ((fff + k1) % 10);
              d *= 10;
              ans += (pre + 1) * d;
              d *= 10;
              k1 = k2 = 0;
              flag = 0;
            }
          } else if (fff + k2 > 9) {
            if (a % 10 == 3 || a % 10 == 4 || a % 10 == 6 || a % 10 == 7) {
              ans += d * k1;
              k1 = a % 10;
              k2 = c % 10;
              a /= 10;
              c /= 10;
              d *= 10;
            } else {
              ans += d * (k1 + fff);
              d *= 10;
              k1 = k2 = 0;
              flag = 0;
            }
          } else {
            ans += d * (k1 + fff);
            d *= 10;
            k1 = k2 = 0;
            flag = 0;
          }
        }
      }
      while (flag) {
        if (k1 == k2) {
          if (k1 == 4) {
            ans += d * 7;
            d *= 10;
            flag = 0;
          } else if (k1 == 7) {
            int pre = a % 10;
            a /= 10;
            c = a;
            if (pre == 4 || pre == 7) {
              ans += d * 4;
              k1 = k2 = pre;
              d *= 10;
            } else if (pre == 3 || pre == 6) {
              d *= 10;
              ans += (pre + 1) * d;
              d *= 10;
              flag = 0;
            } else if (pre == 9) {
              ans += d * 4;
              k1 = k2 = pre;
              d *= 10;
            } else {
              ans += d * 4;
              d *= 10;
              ans += (pre + 1) * d;
              d *= 10;
              flag = 0;
            }
          } else if (k1 == 9) {
            int pre = a % 10;
            a /= 10;
            c = a;
            if (pre == 4 || pre == 7) {
              k1 = k2 = pre;
              d *= 10;
            } else if (pre == 3 || pre == 6) {
              d *= 10;
              ans += (pre + 2) * d;
              d *= 10;
              flag = 0;
            } else if (pre == 9) {
              d *= 10;
              k1 = k2 = pre;
            } else {
              d *= 10;
              ans += (pre + 1) * d;
              d *= 10;
              flag = 0;
            }
          } else if (k1 == 3 || k1 == 6) {
            ans += d * (k1 + 2);
            d *= 10;
            flag = 0;
          } else {
            ans += d * (k1 + 1);
            d *= 10;
            flag = 0;
          }
        }
      }
      printf("%I64d\n", a * d + ans + e);
    }
  }
  return 0;
}
