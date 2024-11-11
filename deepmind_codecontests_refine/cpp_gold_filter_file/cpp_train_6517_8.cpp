#include <bits/stdc++.h>
using namespace std;
const int MAXN = 100005;
vector<int> v[MAXN];
long long ans;
int tr[MAXN];
int n;
void Add(int pos, int val) {
  pos++;
  for (int x = pos; x <= n; x += x & (-x)) tr[x] += val;
  return;
}
int Sum(int pos) {
  int ret = 0;
  pos++;
  for (int x = pos; x > 0; x -= x & (-x)) ret += tr[x];
  return ret;
}
int Count(int l, int r) {
  if (l <= r)
    return Sum(r) - Sum(l);
  else
    return Sum(n - 1) - Sum(l) + Sum(r);
}
int main() {
  scanf("%d", &n);
  for (int i = 0, x; i < n; ++i) scanf("%d", &x), v[x].push_back(i), Add(i, 1);
  for (int i = 1; i < MAXN; ++i) sort(v[i].begin(), v[i].end());
  for (int i = 1, pre = -1; i < MAXN; ++i)
    if (!v[i].empty()) {
      vector<int>::iterator it = upper_bound(v[i].begin(), v[i].end(), pre);
      if (it == v[i].end()) it = v[i].begin();
      ans += Count(pre, *it);
      if (it == v[i].begin())
        ans += Count(v[i].front(), v[i].back()), pre = v[i].back();
      else
        ans += Count(*it, *prev(it)), pre = *prev(it);
      for (auto &x : v[i]) Add(x, -1);
    }
  printf("%I64d\n", ans);
  return 0;
}
