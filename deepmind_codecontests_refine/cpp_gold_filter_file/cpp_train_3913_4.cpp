#include <bits/stdc++.h>
using namespace std;
const int N = 100005;
struct Chain {
  Chain *next;
  int u;
} * Head[N];
int Size[N], ans[N];
int n, root;
bool big[N];
map<int, int> mp, Other, Fa;
void getSize(int u) {
  Size[u] = 1;
  ans[u] = n - 1;
  for (Chain *tp = Head[u]; tp; tp = tp->next) {
    getSize(tp->u);
    Size[u] += Size[tp->u];
  }
  Other[Size[u]]++;
}
void Add(int u, int v) {
  Chain *tp = new Chain;
  tp->u = v;
  tp->next = Head[u];
  Head[u] = tp;
}
void bs(map<int, int> &mp1, int l, int r, int Min, int u, int off) {
  if (Min == n - 1) return;
  int Max = r;
  while (r - l > 1) {
    int Mind = (r + l) / 2;
    map<int, int>::iterator it = mp1.lower_bound(Max - Mind + off);
    if (it == mp1.end())
      l = Mind;
    else if (Min + it->first <= Mind + off)
      r = Mind;
    else
      l = Mind;
  }
  ans[u] = min(ans[u], r);
}
void add(int u) {
  mp[Size[u]]++;
  if (Other[Size[u]] == 1)
    Other.erase(Size[u]);
  else
    Other[Size[u]]--;
  for (Chain *tp = Head[u]; tp; tp = tp->next)
    if (!big[tp->u]) add(tp->u);
}
void Del(int u) {
  Other[Size[u]]++;
  if (mp[Size[u]] == 1)
    mp.erase(Size[u]);
  else
    mp[Size[u]]--;
  for (Chain *tp = Head[u]; tp; tp = tp->next)
    if (!big[tp->u]) Del(tp->u);
}
void dfs(int u, bool isbig) {
  Fa[Size[u]]++;
  if (Other[Size[u]] == 1)
    Other.erase(Size[u]);
  else
    Other[Size[u]]--;
  int Max = -1, SecMax = -1, MaxSon = -1, Min = n - 1;
  for (Chain *tp = Head[u]; tp; tp = tp->next) {
    if (Size[tp->u] > Max) {
      SecMax = Max;
      Max = Size[tp->u];
      MaxSon = tp->u;
    } else if (Size[tp->u] == Max)
      SecMax = Max;
    else
      SecMax = max(SecMax, Size[tp->u]);
    Min = min(Min, Size[tp->u]);
  }
  if (u != root) Min = min(Min, n - Size[u]);
  for (Chain *tp = Head[u]; tp; tp = tp->next) {
    if (tp->u != MaxSon) dfs(tp->u, 0);
  }
  if (MaxSon != -1) {
    big[MaxSon] = true;
    dfs(MaxSon, 1);
  }
  if (Max >= n - Size[u]) {
    SecMax = max(SecMax, n - Size[u]);
    bs(mp, SecMax - 1, Max, Min, u, 0);
  }
  Other[Size[u]]++;
  add(u);
  if (Fa[Size[u]] == 1)
    Fa.erase(Size[u]);
  else
    Fa[Size[u]]--;
  if (n - Size[u] > Max) {
    SecMax = Max;
    bs(Other, SecMax - 1, n - Size[u], Min, u, 0);
    bs(Fa, SecMax - 1, n - Size[u], Min, u, Size[u]);
  }
  if (MaxSon != -1) big[MaxSon] = false;
  if (!isbig) Del(u);
}
int main() {
  int i, u, v;
  scanf("%d", &n);
  for (i = 0; i < n; ++i) {
    scanf("%d%d", &u, &v);
    if (u == 0)
      root = v;
    else
      Add(u, v);
  }
  getSize(root);
  dfs(root, 1);
  for (i = 1; i <= n; ++i) printf("%d\n", ans[i]);
}
