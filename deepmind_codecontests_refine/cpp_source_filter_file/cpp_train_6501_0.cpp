#include <bits/stdc++.h>
using namespace std;
const int sz = 320, N = 100005;
int cnt[sz][N];
deque<int> block[sz];
int qry(int l, int r, int k) {
  int lid = l / sz, rid = r / sz, L = l % sz, R = r % sz;
  int res = 0;
  if (lid == rid) {
    for (int i = L; i <= R; i++)
      if (block[lid][i] == k) res++;
    return res;
  }
  for (int i = L; i < sz; i++)
    if (block[lid][i] == k) res++;
  for (int i = lid + 1; i < rid; i++) res += cnt[i][k];
  for (int i = 0; i <= R; i++)
    if (block[rid][i] == k) res++;
  return res;
}
void upd(int l, int r) {
  if (l == r) return;
  int L = l % sz, R = r % sz, lid = l / sz, rid = r / sz;
  int sv = block[lid][R];
  if (lid == rid) {
    block[lid].erase(block[lid].begin() + R);
    block[lid].insert(block[lid].begin() + L, sv);
    return;
  }
  cnt[rid][sv]--;
  block[rid].erase(block[rid].begin() + R);
  for (int i = lid; i < rid; i++) {
    int x = block[i].back();
    block[i].pop_back();
    cnt[i][x]--;
    cnt[i + 1][x]++;
    block[i + 1].push_front(x);
  }
  block[lid].insert(block[lid].begin() + L, sv);
  cnt[lid][sv]++;
}
int main() {
  int n, q, t, lastans = 0, l, r, k;
  scanf("%d", &n);
  for (int i = 0, a; i < n; i++)
    scanf("%d", &a), cnt[i / sz][a]++, block[i / sz].push_back(a);
  scanf("%d", &q);
  while (q--) {
    scanf("%d%d%d", &t, &l, &r);
    l = ((l + lastans - 1) % n) + 1;
    r = ((r + lastans - 1) % n) + 1;
    if (l > r) swap(l, r);
    l--;
    r--;
    if (t == 1)
      upd(l, r);
    else {
      scanf("%d", &k);
      k = ((k + lastans - 1) % n) + 1;
      int res = qry(l, r, k);
      cout << res << "\n";
      lastans = res;
    }
  }
  return 0;
}
