#include <bits/stdc++.h>
using namespace std;
const int N = 2e5 + 10, M = 3;
int n, Q, ans;
char s[N];
set<int> st[M];
int read() {
  int ret = 0, f = 1;
  char c = getchar();
  while (!isdigit(c)) {
    if (c == '-') f = 0;
    c = getchar();
  }
  while (isdigit(c)) ret = ret * 10 + (c ^ 48), c = getchar();
  return f ? ret : -ret;
}
struct BIT {
  int c[N];
  void update(int x, int v) {
    for (; x < N; x += (x & (-x))) c[x] += v;
  }
  int query(int x) {
    int res = 0;
    for (; x; x -= (x & (-x))) res += c[x];
    return res;
  }
} bit[M];
int id(char c) {
  if (c == 'R')
    return 0;
  else if (c == 'S')
    return 1;
  return 2;
}
int calc(int p) {
  int win = (p + 1) % M, lose = (p - 1 + M) % M;
  if (st[p].empty()) return bit[win].query(n);
  if (st[lose].empty()) return 0;
  return bit[win].query(n) -
         bit[win].query(max(*st[p].begin(), *st[lose].begin())) +
         bit[win].query(*st[lose].rbegin()) -
         bit[win].query(*st[lose].begin()) +
         bit[win].query(min(*st[p].begin(), *st[lose].begin()));
}
int main() {
  n = read();
  Q = read();
  scanf("%s", s + 1);
  for (int i = 1; i <= n; ++i) {
    int p = id(s[i]);
    bit[p].update(i, 1);
    st[p].insert(i);
  }
  ans = calc(0) + calc(1) + calc(2);
  printf("%d\n", ans);
  while (Q--) {
    int p = read();
    char ch;
    scanf("%c", &ch);
    if (s[p] == ch) {
      printf("%d\n", ans);
      continue;
    }
    int las = id(s[p]), now = id(ch);
    s[p] = ch;
    bit[las].update(p, -1);
    bit[now].update(p, 1);
    st[las].erase(p);
    st[now].insert(p);
    ans = calc(0) + calc(1) + calc(2);
    printf("%d\n", ans);
  }
  return 0;
}
