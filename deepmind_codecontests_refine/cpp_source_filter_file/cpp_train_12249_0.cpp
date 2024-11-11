#include <bits/stdc++.h>
using namespace std;
const long long mod = 1e9 + 7;
const long long INFl = 4223372036854775807ll;
const int inf = 1e9 + 7;
long long power(long long x, long long y, long long z) {
  long long t = 1;
  while (y > 0) {
    if (y % 2) {
      t = (t * x) % z;
    }
    x = (x * x) % z;
    y /= 2;
  }
  return t;
}
long long multipw(long long x, long long y, long long z) {
  long long sum = 0ll;
  while (y > 0) {
    if (y % 2) (sum += x) %= (long long)1e17;
    x = (x + x) % (long long)1e17;
    y /= 2;
  }
  return sum;
}
int movex[4] = {0, 1, -1, 0};
int movey[4] = {1, 0, 0, -1};
int movexx[8] = {-1, 0, 1, 1, 1, 0, -1, -1};
int moveyy[8] = {1, 1, 1, 0, -1, -1, -1, 0};
const int RIGHT = (1 << 20);
const int RR = 1e9;
const long long limit = 1e11 + 5;
int pr[200005 * 10 + 100];
const int CR = 2e6;
int primes[200005 * 10 + 100];
int a[200005 * 10 + 100];
int sz;
bool f[200005 * 10 + 100];
int main() {
  for (int i = 2; i <= CR; i++)
    if (pr[i] == 0) {
      primes[sz++] = i;
      for (int j = i; j <= CR; j += i) pr[j] = i;
    }
  int n, m;
  int tmp;
  bool ok = false;
  scanf("%d", &n);
  for (int i = 0; i < n; i++) {
    scanf("%d", &m);
    if (ok) continue;
    int def = m;
    while (m > 1) {
      tmp = m;
      while (tmp > 1) {
        if (f[pr[tmp]] == 1) {
          break;
        }
        tmp /= pr[tmp];
      }
      if (tmp > 1) {
        m++;
      } else {
        tmp = m;
        while (m > 1) {
          f[pr[m]] = 1;
          m /= pr[m];
        }
      }
    }
    if (def != m) {
      ok = true;
    }
    a[i] = tmp;
  }
  int nw = 2;
  for (int i = 0; i < n; i++)
    if (a[i] == 0) {
      for (;;) {
        tmp = nw;
        while (tmp > 1) {
          if (f[pr[tmp]] == 1) {
            break;
          }
          tmp /= pr[tmp];
        }
        if (tmp > 1) {
          nw++;
        } else {
          tmp = nw;
          a[i] = nw;
          while (tmp > 1) {
            f[pr[tmp]] = 1;
            tmp /= pr[tmp];
          }
          break;
        }
      }
    }
  for (int i = 0; i < n; i++) printf("%d ", a[i]);
  return 0;
}
