#include <bits/stdc++.h>
int inp() {
  char c = getchar();
  while (c < '0' || c > '9') c = getchar();
  int sum = 0;
  while (c >= '0' && c <= '9') {
    sum = sum * 10 + c - '0';
    c = getchar();
  }
  return sum;
}
std::unordered_map<int, int> used;
int fa[400010], sum[400010];
int find(int x) {
  if (fa[x] == x) return fa[x];
  int ret = find(fa[x]);
  sum[x] ^= sum[fa[x]];
  fa[x] = ret;
  return ret;
}
int main() {
  int q = inp();
  int lastans = 0;
  int cnt = 0;
  for (int i = 1; i <= 40000; i++) fa[i] = i;
  while (q--) {
    int op = inp();
    if (op == 1) {
      int l = inp() ^ lastans;
      int r = inp() ^ lastans;
      int c = inp() ^ lastans;
      if (l > r) std::swap(l, r);
      r++;
      if (!used[l]) used[l] = ++cnt;
      if (!used[r]) used[r] = ++cnt;
      l = used[l];
      r = used[r];
      if (find(l) == find(r)) continue;
      int fl = find(l);
      fa[fl] = find(r);
      sum[fl] = sum[r] ^ sum[l] ^ c;
    } else {
      int l = inp() ^ lastans;
      int r = inp() ^ lastans;
      if (l > r) std::swap(l, r);
      l = used[l];
      r = used[r + 1];
      if (find(l) != find(r) || (!l) || (!r)) {
        lastans = 1;
        printf("-1\n");
      } else {
        lastans = sum[r] ^ sum[l];
        printf("%d\n", lastans);
      }
    }
  }
}
