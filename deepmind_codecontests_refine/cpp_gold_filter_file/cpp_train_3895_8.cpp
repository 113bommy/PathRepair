#include <bits/stdc++.h>
using namespace std;
const int INF = 0x3fffffff;
const int SINF = 0x7fffffff;
const long long LINF = 0x3fffffffffffffff;
const long long SLINF = 0x7fffffffffffffff;
int a, n, p, h;
void init();
void input();
void work();
int getmin(int n, int a, int p, bool flag = false);
int main() {
  init();
  int T;
  scanf("%d", &T);
  while (T--) {
    input();
    work();
  }
}
void init() { ios::sync_with_stdio(false); }
void input() { scanf("%d%d%d%d", &a, &n, &p, &h); }
void work() {
  a %= p;
  int mini = getmin(n, a, p);
  printf((h >= mini) ? "YES\n" : "NO\n");
}
int getmin(int n, int a, int p, bool flag) {
  long long nto = static_cast<long long>(a) * n;
  if (nto < p)
    return flag ? (((a) > (p - static_cast<int>(nto)))
                       ? (a)
                       : (p - static_cast<int>(nto)))
                : a;
  int nc = nto / p;
  int rem = n - static_cast<long long>(nc) * p / a;
  if (rem >= p / a) ++nc;
  --nc;
  return getmin(nc, min(p % a, (a - p % a) % a), a, true);
}
