#include <bits/stdc++.h>
using namespace std;
const int maxn = (int)1e6 + 5;
const long long maxx = (long long)10000001;
const int maxm = (int)2e3 + 5;
const int INF = 0x3f3f3f3f;
const long long inf = 0x3f3f3f3f3f3f3f3f;
const double eps = 1e-6;
const int MOD = (int)1e9 + 7;
template <class T>
inline void read(T &x) {
  x = 0;
  T flag = 1;
  char c;
  do {
    c = (char)getchar();
    if (c == '-') break;
  } while (c < '0' || c > '9');
  if (c == '-') {
    c = '0', flag = -1;
  }
  do {
    x = x * 10 + c - '0';
    c = (char)getchar();
  } while (c >= '0' && c <= '9');
  x *= flag;
}
template <class T>
inline void out(T x) {
  if (x > 9) out(x / 10);
  x = x % 10;
  putchar('0' + x);
}
int value[maxx][2];
int main() {
  int n;
  read(n);
  int x;
  for (int i = 1; i <= n; i++) {
    read(x);
    if (value[x][0] != 0) {
      value[x][1] = i;
    } else {
      value[x][0] = i;
    }
  }
  long long ans = 1LL * maxx * maxx;
  int ansx = 1, ansy = 1;
  int vsize = 0;
  int v[2];
  for (int i = 1; i < maxx; ++i) {
    if (i >= ans) {
      break;
    }
    vsize = 0;
    long tmp = i;
    for (int j = 1; j * i < maxx; ++j) {
      if (value[j * i][0] != 0) {
        v[vsize] = value[j * i][0];
        ++vsize;
        tmp *= j;
        if (vsize >= 2) {
          break;
        }
      }
      if (value[j * i][1] != 0) {
        v[vsize] = value[j * i][1];
        ++vsize;
        tmp *= j;
        if (vsize >= 2) {
          break;
        }
      }
    }
    if (vsize < 2) {
      continue;
    }
    if (tmp < ans) {
      ans = tmp;
      ansx = v[0];
      ansy = v[1];
    }
  }
  if (ansx > ansy) {
    int tmp = ansx;
    ansx = ansy;
    ansy = tmp;
  }
  printf("%d %d\n", ansx, ansy);
  return 0;
}
