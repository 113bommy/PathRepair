#include <bits/stdc++.h>
using namespace std;
const int N = 2e5 + 5;
const int M = 2e3 + 50;
const int INF = 0x7fffffff;
const int mod = 1e9 + 7;
const int sz = 18;
const double eps = 1e-10;
const double pi = acos(-1);
long long n, m;
char str[N];
int f[N];
template <class T>
inline void read(T &x) {
  char c;
  x = 1;
  while ((c = getchar()) < '0' || c > '9')
    if (c == '-') x = -1;
  T res = c - '0';
  while ((c = getchar()) >= '0' && c <= '9') res = res * 10 + c - '0';
  x *= res;
}
int main() {
  int t;
  read(t);
  while (t--) {
    read(n);
    read(m);
    long long l, r;
    for (int i = 1; i <= n; i++) {
      long long tmp = 1ll * i * (i - 1) / 2;
      if (tmp >= m) {
        l = i;
        break;
      }
    }
    r = (l - 1) - ((l - 1) * l / 2 - m);
    l = n - l + 1;
    r = n - r + 1;
    for (int i = 1; i <= n; i++) {
      if (i == l || i == r)
        cout << 'b';
      else
        cout << 'a';
    }
    cout << endl;
  }
  return 0;
}
