#include <bits/stdc++.h>
using namespace std;
double PI = acos(-1.);
inline long long read() {
  long long X = 0, w = 0;
  char ch = 0;
  while (!isdigit(ch)) {
    w |= ch == '-';
    ch = getchar();
  }
  while (isdigit(ch)) X = (X << 3) + (X << 1) + (ch ^ 48), ch = getchar();
  return w ? -X : X;
}
inline void write(long long x) {
  if (x < 0) putchar('-'), x = -x;
  if (x > 9) write(x / 10);
  putchar(x % 10 + '0');
}
class Tp {
 public:
  long long x, c, id;
  bool operator<(const Tp& tmp) const { return c < tmp.c; }
  void init() { x = read(), c = read(); }
} a[(3000 + 100)];
vector<Tp> ve[(3000 + 100)];
long long n, m;
bool vis[(3000 + 100)];
long long check(long long x) {
  memset(vis, 0, sizeof(vis));
  long long ans = 0, qq = ve[1].size();
  for (auto it : ve[1]) vis[it.id] = 1;
  for (long long i = 2; i <= m; i++) {
    long long num = ve[i].size();
    if (num < x) continue;
    num = x - num + 1;
    for (long long j = 0; j < num; j++) {
      ans += ve[i][j].c;
      vis[ve[i][j].id] = 1;
    }
    qq += num;
  }
  for (long long i = 1; i <= n && qq < x; i++) {
    if (vis[i]) continue;
    ans += a[i].c;
    qq++;
  }
  return ans;
}
int main() {
  n = read(), m = read();
  for (long long i = 1; i <= m; i++) ve[i].clear();
  for (long long i = 1; i <= n; i++) a[i].init();
  sort(a + 1, a + n + 1);
  for (long long i = 1; i <= n; i++) {
    a[i].id = i;
    ve[a[i].x].push_back(a[i]);
  }
  for (long long i = 1; i <= m; i++) sort(ve[i].begin(), ve[i].end());
  long long ans = (1000000000000000000);
  for (long long i = 1; i <= n; i++) {
    long long tmp = check(i);
    ans = min(ans, tmp);
  }
  write(ans), putchar('\n');
  return 0;
}
