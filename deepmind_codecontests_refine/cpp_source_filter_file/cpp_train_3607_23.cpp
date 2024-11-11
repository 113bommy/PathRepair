#include <bits/stdc++.h>
using namespace std;
inline int readint() {
  int a = 0;
  char c = getchar(), f = 1;
  for (; c < '0' || c > '9'; c = getchar())
    if (c == '-') f = -f;
  for (; '0' <= c && c <= '9'; c = getchar())
    a = (a << 3) + (a << 1) + (c ^ 48);
  return a * f;
}
const int MaxN = 2005;
char s[MaxN];
int n;
int findIt(int id, char want) {
  for (int i = id; i <= n; ++i)
    if (s[i] == want) return i;
  return -1;
}
vector<int> ans;
void shift(int x) {
  if (!x) return;
  ans.push_back(x);
  reverse(s + 1, s + n + 1);
  reverse(s + x + 1, s + n + 1);
}
void tiny_sy(int now, int id) {
  shift(n - id);
  shift(id - now);
  shift(now);
}
char t[MaxN];
void solve() {
  int l = (n >> 1) + 1, r = l - 1, x;
  if (n & 1) {
    x = findIt(1, t[l]);
    r = l;
    if (x == -1) {
      puts("-1");
      return;
    }
    tiny_sy(0, x);
  }
  while (1 < l || r < n) {
    x = findIt(r - l + 1, t[l - 1]);
    if (x == -1) {
      puts("-1");
      return;
    }
    tiny_sy(r - l + 1, x);
    --l;
    x = findIt(r - l + 1, t[r + 1]);
    if (x == -1) {
      puts("-1");
      return;
    }
    tiny_sy(r - l + 1, x);
    ++r;
  }
  int len = ans.size();
  printf("%d\n", len);
  for (int i = 0; i < len; ++i) printf("%d\n", ans[i]);
}
int main() {
  n = readint();
  scanf("%s %s", s + 1, t + 1);
  solve();
  return 0;
}
