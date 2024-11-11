#include <bits/stdc++.h>
using namespace std;
const int N = 500010;
int fa[N], size[N], cnt, now = 1, block = 400, lst, fst = 1, top;
struct node {
  int now, x, y;
} o[N], st[N];
int read() {
  int x = 0;
  char c = getchar(), flag = '+';
  while (!isdigit(c)) flag = c, c = getchar();
  while (isdigit(c)) x = x * 10 + c - '0', c = getchar();
  return flag == '-' ? -x : x;
}
int find(int x) { return x == fa[x] ? x : find(fa[x]); }
void merge(int x, int y) {
  x = find(x), y = find(y);
  if (size[x] < size[y]) swap(x, y);
  st[++top] = {0, x, y};
  if (x == y) return;
  fa[y] = x, size[x] += size[y];
}
void ctrlz() {
  int x = st[top].x, y = st[top--].y;
  if (x == y) return;
  fa[y] = y, size[x] -= size[y];
}
int main() {
  int n = read(), q = read(), k = read();
  for (int i = 1; i <= n; i++) fa[i] = i, size[i] = 1;
  while (q--) {
    int t = read();
    if (t == 1) {
      int x = read(), y = read();
      o[++cnt] = {now, x, y};
      if (cnt % block == 0) {
        lst = cnt, top = 0;
        for (int j = 1; j <= n; j++) fa[j] = j, size[j] = 1;
        for (int j = cnt; j >= fst; j--) merge(o[j].x, o[j].y);
      }
    } else if (t == 2) {
      int x = read(), tmp = max(lst + 1, fst);
      for (int j = tmp; j <= cnt; j++) merge(o[j].x, o[j].y);
      cout << size[find(x)] << '\n';
      for (int j = cnt; j >= tmp; j--) ctrlz();
    } else if (t == 3) {
      now++;
      while (fst <= cnt && now - o[fst].now + 1 > k) {
        if (fst <= lst) ctrlz();
        fst++;
      }
    }
  }
  return 0;
}
