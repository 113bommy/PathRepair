#include <bits/stdc++.h>
using namespace std;
template <typename T>
inline void checkmin(T &a, T b) {
  if (a > b) a = b;
}
const int N = (1 << 19);
const int M = (1 << 18);
long long s[N];
long long del_root(int a) {
  if (a == 0) return 0LL;
  long long res = 0L;
  res += del_root(a >> 1);
  if (a & 1)
    s[a - 1] += res;
  else
    s[a + 1] += res;
  res += s[a];
  s[a] = 0;
  return res;
}
long long del_001(int a) {
  long long res = 0LL;
  a += M;
  res += del_root(a);
  return res;
}
long long del(int a) {
  long long res = 0LL;
  a += M;
  int b = a;
  while (1) {
    if (a == 0) break;
    res += s[a];
    a >>= 1;
  }
  s[b] -= res;
  return res;
}
void add(int a, int b, int x) {
  a += M;
  b += M;
  while (1) {
    if (a > b)
      break;
    else if (a == b) {
      s[a] += x;
      break;
    }
    if ((a & 1) == 1) {
      s[a] += x;
      a++;
    }
    if ((b & 1) == 0) {
      s[b] += x;
      b--;
    }
    a >>= 1;
    b >>= 1;
  }
}
void solve() {
  for (int i = 0; i < (N); i++) s[i] = 0LL;
  int n = 0, t, x, a, k;
  scanf("%d", &n);
  int sz = 1;
  long long sum = 0LL;
  for (int i = 0; i < (n); i++) {
    scanf("%d", &t);
    if (t == 1) {
      scanf("%d %d", &a, &x);
      add(0, a - 1, x);
      sum += a * x;
    } else if (t == 2) {
      scanf("%d", &k);
      s[sz + M] += k;
      sz++;
      sum += k;
    } else if (t == 3) {
      sz--;
      sum -= del(sz);
    }
    printf("%.6lf\n", sum * 1.0 / sz);
  }
}
int main() {
  solve();
  return 0;
}
