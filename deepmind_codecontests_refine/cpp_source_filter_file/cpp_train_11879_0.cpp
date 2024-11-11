#include <bits/stdc++.h>
using namespace std;
const int inf = 1000000000;
const int N = 300005;
int l[N], r[N], n, rk;
struct node {
  int l, r, c;
  bool operator<(const node &a) const { return l == a.l ? r < a.r : l < a.l; }
};
set<node> S;
vector<pair<int, int> > dif[N];
void split(int p) {
  set<node>::iterator it;
  it = S.lower_bound((node){p, 0, 0});
  if (it->l == p) return;
  it--;
  int l = it->l, r = it->r, c = it->c;
  S.erase(it);
  S.insert((node){l, p - 1, c});
  S.insert((node){p, r, c});
}
void work(int l, int r, int id) {
  set<node>::iterator it;
  it = S.lower_bound((node){l, 0, 0});
  for (; it->l <= r; S.erase(it++))
    dif[id].push_back(pair<int, int>(it->c, -(it->r - it->l + 1)));
  dif[id].push_back(pair<int, int>(id, r - l + 1));
  S.insert((node){l, r, id});
}
void build_chg() {
  S.clear();
  S.insert((node){1, inf, 0});
  S.insert((node){inf + 1, inf + 1, 0});
  for (int i = (int)(1); i <= (int)(n); i++) {
    split(l[i]);
    split(r[i] + 1);
    work(l[i], r[i], i);
  }
}
long long Func(int v) {
  static int a[N];
  memset(a, 0, sizeof(a));
  int p = 1, s = 0;
  a[0] = inf;
  long long ans = 0;
  for (int i = (int)(1); i <= (int)(n); i++) {
    for (auto j : dif[i]) {
      a[j.first] += j.second;
      if (p <= j.first) s += j.second;
    }
    for (; s >= v; s -= a[p++])
      ;
    ans += p - 1;
  }
  return ans;
}
long long Func2(int v) {
  static int a[N];
  memset(a, 0, sizeof(a));
  int p = 1, s = 0;
  a[0] = inf;
  long long ans = 0, ss = 0, sss = 0;
  for (int i = (int)(1); i <= (int)(n); i++) {
    for (auto j : dif[i]) {
      a[j.first] += j.second;
      if (j.first >= p) s += j.second;
      sss += min(j.first, p - 1) * j.second;
    }
    for (; s >= v;) sss += s, s -= a[p++];
    ans += sss;
  }
  return ans;
}
int main() {
  scanf("%d%d", &n, &rk);
  for (int i = (int)(1); i <= (int)(n); i++)
    scanf("%d%d", &l[i], &r[i]), --r[i];
  build_chg();
  int l = 0, r = inf, ans;
  while (l <= r) {
    int mid = (l + r) / 2;
    if (Func(mid) >= rk)
      ans = mid, l = mid + 1;
    else
      r = mid - 1;
  }
  long long res = Func2(ans) - (Func(ans) - rk) * ans;
  printf("%lld\n", res);
}
