#include <bits/stdc++.h>
using namespace std;
const int N = 2e5 + 7;
const int maxn = 2e5 + 2;
int c[N << 2];
int lowbit(int x) { return (x) & (-x); }
void add(int x, int v) {
  for (int i = x; i >= 1; i -= lowbit(i)) {
    c[i] += v;
  }
}
int sum(int x) {
  int res = 0;
  for (int i = x; i < maxn; i += lowbit(i)) res += c[i];
  return res;
}
map<int, int> mp;
struct inte {
  int l, r, id;
};
int cmpinte(inte a, inte b) {
  if (a.r == b.r) return a.l < b.l;
  return a.r < b.r;
}
inte arry[N];
int shan[N * 3];
int ans[N];
int main() {
  memset(c, 0, sizeof c);
  int n;
  scanf("%d", &n);
  for (int i = 1; i <= n; i++) scanf("%d%d", &arry[i].l, &arry[i].r);
  for (int i = 1; i <= n; i++) {
    shan[i * 2 - 1] = arry[i].l;
    shan[i * 2] = arry[i].r;
  }
  sort(shan + 1, shan + 1 + 2 * n);
  int sz = 0;
  for (int i = 1; i <= 2 * n; i++) {
    if (!mp.count(shan[i])) {
      ++sz;
      mp[shan[i]] = sz;
    }
  }
  for (int i = 1; i <= n; i++) {
    arry[i].l = mp[arry[i].l];
    arry[i].r = mp[arry[i].r];
    arry[i].id = i;
  }
  sort(arry + 1, arry + 1 + n, cmpinte);
  memset(c, 0, sizeof c);
  for (int i = 1; i <= n; i++) {
    ans[arry[i].id] = sum(arry[i].l);
    add(arry[i].l, 1);
  }
  for (int i = 1; i <= n; i++) printf("%d\n", ans[i]);
}
