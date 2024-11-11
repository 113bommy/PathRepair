#include <bits/stdc++.h>
const double EPS = 1e-10;
using namespace std;
inline int rit() {
  int f = 0, key = 1;
  char c;
  do {
    c = getchar();
    if (c == '-') key = -1;
  } while (c < '0' || c > '9');
  do {
    f = f * 10 + c - '0';
    c = getchar();
  } while (c >= '0' && c <= '9');
  return f * key;
}
int n, k, gc;
long long a[300005];
char mk[5005][5005];
long long ans[5005][5005];
long long go(int p, int x, int siz) {
  long long ff = 2e9;
  if (!p) return 0;
  if (mk[p][x]) return ans[p][x];
  mk[p][x] = 1;
  if (x) ff = min(ff, a[siz] - a[siz - gc + 1] + go(p - 1, x - 1, siz - gc));
  if (p > x)
    ff = min(ff, a[siz] - a[siz - n / k + 1] + go(p - 1, x, siz - n / k));
  ans[p][x] = ff;
  return ans[p][x];
}
void read() {
  int i, f;
  n = rit(), k = rit();
  for (i = 1; i <= n; i++) a[i] = rit();
  sort(a + 1, a + n + 1);
  gc = n / k + (n % k == 0 ? 0 : 1);
  cout << go(k, n % k, n) << endl;
}
int main() {
  read();
  return 0;
}
