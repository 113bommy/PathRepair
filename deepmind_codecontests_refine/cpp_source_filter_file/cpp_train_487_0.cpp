#include <bits/stdc++.h>
using namespace std;
template <typename T>
void chmin(T &x, const T &y) {
  if (x > y) x = y;
}
template <typename T>
void chmax(T &x, const T &y) {
  if (x < y) x = y;
}
int read() {
  char c;
  while ((c = getchar()) < '-')
    ;
  if (c == '-') {
    int x = (c = getchar()) - '0';
    while ((c = getchar()) >= '0') x = x * 10 + c - '0';
    return -x;
  }
  int x = c - '0';
  while ((c = getchar()) >= '0') x = x * 10 + c - '0';
  return x;
}
const int N = 50 + 5;
int fa[N], du[N];
int find(int x) { return fa[x] == x ? x : fa[x] = find(fa[x]); }
pair<int, int> ans[N];
int main() {
  int n = read(), m = read();
  for (int i = 1; i <= n; ++i) fa[i] = i;
  for (int i = 1; i <= m; ++i) {
    int x = read(), y = read();
    ++du[x];
    ++du[y];
    fa[find(x)] = find(y);
  }
  for (int i = 1; i <= n; ++i)
    if (du[i] > 2) {
      puts("NO");
      return 0;
    }
  int top = 0;
  for (int i = 1; i <= n; ++i)
    for (int j = i; j <= n; ++j)
      if (find(i) != find(j) && du[i] < 2 && du[j] < 2) {
        ans[++top] = make_pair(i, j);
        ++du[i];
        ++du[j];
        fa[find(i)] = find(j);
      }
  if (m + top == n - 1) {
    ++top;
    for (int i = 1; i <= n; ++i)
      while (du[i] < 2) {
        ++du[i];
        if (!ans[top].first)
          ans[top].first = i;
        else
          ans[top].second = i;
      }
  }
  for (int i = 1; i <= n; ++i)
    if (find(i) != find(1)) {
      puts("NO");
      return 0;
    }
  puts("YES");
  printf("%d\n", top);
  for (int i = 1; i <= top; ++i) printf("%d %d", ans[i].first, ans[i].second);
}
