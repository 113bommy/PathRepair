#include <bits/stdc++.h>
#pragma comment(linker, "/stack:200000000")
#pragma GCC optimize("Ofast")
#pragma target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")
using namespace std;
inline long long read() {
  long long t = 0, dp = 1;
  char c = getchar();
  while (!isdigit(c)) {
    if (c == '-') dp = -1;
    c = getchar();
  }
  while (isdigit(c)) t = t * 10 + c - 48, c = getchar();
  return t * dp;
}
inline void write(long long x) {
  if (x < 0) {
    putchar('-');
    x = -x;
  }
  if (x >= 10) write(x / 10);
  putchar(x % 10 + 48);
}
inline void writeln(long long x) {
  write(x);
  puts("");
}
inline void write_p(long long x) {
  write(x);
  putchar(' ');
}
const int N = 2e6 + 20;
int poi[N], nxt[N], head[N], dp[N], mx[N], n, k, rt, cnt, in[N];
inline void add(int x, int y) {
  poi[++cnt] = y;
  nxt[cnt] = head[x];
  head[x] = cnt;
  poi[++cnt] = x;
  nxt[cnt] = head[y];
  head[y] = cnt;
  in[x]++;
  in[y]++;
}
inline void Dfs(int x, int fa) {
  if (in[x] == 1) dp[x] = 1;
  vector<int> tmp;
  for (int i = head[x]; i; i = nxt[i]) {
    if (poi[i] == fa) continue;
    Dfs(poi[i], x);
    tmp.push_back(mx[poi[i]] + 1);
    dp[x] += dp[poi[i]];
  }
  if (tmp.empty()) return;
  sort(tmp.begin(), tmp.end());
  int siz = (int)tmp.size();
  if (siz > 1) {
    if (tmp[siz - 1] + tmp[siz - 2] <= k)
      dp[x] -= siz - 1, mx[x] = tmp[siz - 1];
    else
      for (int i = 1; i <= siz - 1; ++i)
        if (tmp[i] + tmp[i - 1] > k) {
          dp[x] -= i - 1;
          mx[x] = tmp[i - 1];
          break;
        }
  } else
    mx[x] = tmp[0];
}
int main() {
  n = read();
  k = read();
  for (int i = 1; i <= n - 1; ++i) add(read(), read());
  for (int i = 1; i <= n; ++i)
    if (in[i] != 1) rt = i;
  Dfs(rt, rt);
  writeln(dp[rt]);
}
