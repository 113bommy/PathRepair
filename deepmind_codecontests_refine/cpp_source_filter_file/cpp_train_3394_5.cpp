#include <bits/stdc++.h>
using namespace std;
const int MAXN = 1e5 + 11;
const int MAXA = 1e6 + 11;
int n, a, x;
int cnt[MAXA];
bool ban[MAXA];
set<int> tree[MAXA];
inline void add(int pos, int val) {
  for (int i = pos; 0 < i && i < MAXN; i += (i & (-i)))
    if (val > 0)
      tree[i].insert(val);
    else if (tree[i].count(-val))
      tree[i].erase(val);
}
inline void rem(int pos) {
  for (int i = pos; i > 0; i -= (i & (-i)))
    while (!tree[i].empty()) {
      ban[*tree[i].begin()] = true;
      tree[i].erase(tree[i].begin());
    }
}
inline void update(int val) {
  add(cnt[val], -val);
  add(++cnt[val], val);
}
int main() {
  scanf("%d%d", &n, &a);
  for (int i = 0; i < n; ++i) {
    scanf("%d", &x);
    if (x == a) {
      update(a), rem(cnt[a]);
      continue;
    }
    if (cnt[x] < cnt[a]) {
      ban[x] = true;
      continue;
    }
    ++cnt[x];
  }
  for (int i = 1; i <= MAXA; ++i)
    if (!ban[i] && cnt[i] >= cnt[a] && i != a) {
      printf("%d\n", i);
      return 0;
    }
  puts("-1");
  return 0;
}
