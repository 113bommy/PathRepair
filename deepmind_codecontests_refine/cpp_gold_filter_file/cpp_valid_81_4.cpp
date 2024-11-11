#include <bits/stdc++.h>
using namespace std;
const double pi = acos(-1.0);
const int INF = 0x3f3f3f3f;
const long long inf = 1e18;
const int N = 3e5 + 10;
const int M = 1e6 + 10;
const int mod = 1e9 + 7;
const double eps = 1e-6;
inline int lowbit(int x) { return x & (-x); }
template <typename T>
void write(T x) {
  if (x < 0) {
    putchar('-');
    x = -x;
  }
  if (x > 9) {
    write(x / 10);
  }
  putchar(x % 10 + '0');
}
template <typename T>
void read(T &x) {
  x = 0;
  char ch = getchar();
  long long f = 1;
  while (!isdigit(ch)) {
    if (ch == '-') f *= -1;
    ch = getchar();
  }
  while (isdigit(ch)) {
    x = x * 10 + ch - 48;
    ch = getchar();
  }
  x *= f;
}
int n, m, k, T;
char s[N];
int s1[N];
int s2[N];
void solve() {
  s1[0] = s2[0] = 0;
  read(n);
  read(m);
  scanf("%s", s + 1);
  for (int i = 1; i <= n; i++) {
    s1[i] = s1[i - 1];
    s2[i] = s2[i - 1];
    if (i & 1) {
      if (s[i] == '+')
        s1[i]++;
      else
        s1[i]--;
    } else {
      if (s[i] == '+')
        s2[i]++;
      else
        s2[i]--;
    }
  }
  while (m--) {
    int l, r;
    read(l), read(r);
    if ((r - l + 1) & 1) {
      puts("1");
      continue;
    }
    int t1 = s1[r] - s1[l - 1];
    int t2 = s2[r] - s2[l - 1];
    int tmp = abs(t1 - t2);
    tmp = min(tmp, 2);
    write(tmp);
    puts("");
  }
}
signed main(void) {
  read(T);
  while (T--) {
    solve();
  }
  return 0;
}
