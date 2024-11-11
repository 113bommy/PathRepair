#include <bits/stdc++.h>
using namespace std;
#pragma comment(linker, "/STACK:102400000,102400000")
const int INF = 0x3f3f3f3f3f, mod = 1e9 + 7;
const double eps = 1e-6, PI = acos(-1);
template <typename T>
inline void read(T &x) {
  x = 0;
  T f = 1;
  char ch;
  do {
    ch = getchar();
    if (ch == '-') f = -1;
  } while (ch < '0' || ch > '9');
  do x = x * 10 + ch - '0', ch = getchar();
  while (ch <= '9' && ch >= '0');
  x *= f;
}
long long a, b, ta, tb;
bool judge(long long x) {
  if (x * (x + 1) / 2 > a + b) return false;
  long long sum = x * (x + 1) / 2;
  ta = a;
  for (long long i = x; i >= 1; i--) {
    if (ta >= i) {
      ta -= i;
      sum -= i;
    }
  }
  return b >= sum;
}
vector<int> ac, bc;
int done[1000000];
void make(long long x) {
  int n = 0, m = 0;
  for (long long i = x; i >= 1; i--) {
    if (a >= i) {
      a -= i;
      n++;
      done[i] = 1;
      ac.push_back(i);
    }
  }
  for (long long i = x; i >= 1; i--) {
    if (!done[i]) {
      m++;
      bc.push_back(i);
    }
  }
  printf("%d\n", n);
  for (int i = 0; i < n; i++) {
    if (i != 0) printf(" ");
    printf("%d", ac[i]);
  }
  puts("");
  printf("%d\n", m);
  for (int i = 0; i < m; i++) {
    if (i != 0) printf(" ");
    printf("%d", bc[i]);
  }
}
int main() {
  read(a), read(b);
  long long l = 1, r = 1e5, ans = 1;
  while (l <= r) {
    long long mid = (l + r) >> 1;
    if (judge(mid))
      l = mid + 1, ans = mid;
    else
      r = mid - 1;
  }
  make(ans);
  return 0;
}
