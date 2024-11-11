#include <bits/stdc++.h>
using namespace std;
int n, t1, a[500001], f[500001], b[500001], po[500001];
vector<int> zh[300001];
int lowbit(int x) { return x & (-x); }
void ins(int x, int t) {
  int i;
  for (i = x; i <= n; i += lowbit(i)) f[i] = max(f[i], t);
}
int query(int x) {
  int i, xlh = 0;
  for (i = x; i; i -= lowbit(i)) xlh = max(xlh, f[i]);
  return xlh;
}
int main() {
  int i, x, flag;
  scanf("%d", &t1);
  while (t1--) {
    flag = 0;
    scanf("%d", &n);
    for (i = 1; i <= n; i++) scanf("%d", &a[i]);
    for (i = 1; i <= n; i++) f[i] = 0, zh[i].clear();
    for (i = 1; i <= n; i++) {
      scanf("%d", &b[i]);
      zh[b[i]].push_back(i);
    }
    for (i = 1; i <= n; i++) reverse(zh[i].begin(), zh[i].end());
    for (i = 1; i <= n; i++) {
      if (!zh[a[i]].size()) {
        flag = 1;
        break;
      }
      po[i] = zh[a[i]].back();
      zh[a[i]].pop_back();
    }
    if (flag) {
      puts("NO");
      continue;
    }
    for (i = 1; i <= n; i++) {
      if (query(a[i] - 1) > po[i]) {
        flag = 1;
        break;
      }
      ins(a[i], po[i]);
    }
    if (flag) {
      puts("NO");
      continue;
    }
    puts("YES");
  }
}
