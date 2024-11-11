#include <bits/stdc++.h>
using namespace std;
int read() {
  int X = 0, p = 1;
  char c = getchar();
  for (; c > '9' || c < '0'; c = getchar())
    if (c == '-') p = -1;
  for (; c >= '0' && c <= '9'; c = getchar()) X = X * 10 + c - '0';
  return X * p;
}
const int N = 2e5 + 5;
int n, m, sum[4][N];
char s[N];
set<int> S[4];
int ch(char c) {
  if (c == 'R') return 0;
  if (c == 'P') return 1;
  if (c == 'S') return 2;
}
void add(int x, int d, int *p) {
  for (; x <= n; x += ((x) & -(x))) p[x] += d;
}
int query(int x, int *p) {
  if (x < 0) return 0;
  int res = 0;
  for (; x; x -= ((x) & -(x))) res += p[x];
  return res;
}
int work(int x) {
  int y = (x + 2) % 3;
  int z = (x + 1) % 3;
  int res = 0;
  if (!S[y].size()) {
    if (S[z].size())
      return 0;
    else
      return n;
  }
  int l = *(S[y].begin()), r = *(--S[y].end());
  if (S[y].size() > 1) res += query(r, sum[x]) - query(l - 1, sum[x]);
  int tmp = S[z].size() ? *(S[z].begin()) : n + 1;
  (tmp = tmp > l ? l : tmp);
  res += query(tmp, sum[x]);
  tmp = S[z].size() ? *(--S[z].end()) : 0;
  (tmp = tmp > r ? tmp : r);
  res += query(n, sum[x]) - query(tmp - 1, sum[x]);
  return res;
}
int main() {
  n = read();
  m = read();
  scanf("%s", s + 1);
  for (int i = 1; i <= n; ++i) {
    add(i, 1, sum[ch(s[i])]);
    S[ch(s[i])].insert(i);
  }
  printf("%d\n", work(0) + work(1) + work(2));
  for (int i = 1; i <= m; ++i) {
    int x = read();
    char c = getchar();
    for (; !(c == 'R' || c == 'P' || c == 'S');) c = getchar();
    S[ch(s[x])].erase(x);
    add(x, -1, sum[ch(s[x])]);
    s[x] = c;
    S[ch(s[x])].insert(x);
    add(x, 1, sum[ch(s[x])]);
    printf("%d\n", work(0) + work(1) + work(2));
  }
}
