#include <bits/stdc++.h>
using namespace std;
const int MN = 200111;
int n, k, p[MN], e[MN], cnt[MN];
vector<int> ls[MN];
struct Node {
  long long sz, sum;
} it[MN * 8];
void insert(int i, int l, int r, int u, int val1, int val2) {
  if (u < l || r < u) return;
  if (l == r) {
    it[i].sz += val1;
    it[i].sum += val2;
    return;
  }
  insert(((i) << 1), l, ((l + r) >> 1), u, val1, val2);
  insert((((i) << 1) + 1), ((l + r) >> 1) + 1, r, u, val1, val2);
  it[i].sz = it[((i) << 1)].sz + it[(((i) << 1) + 1)].sz;
  it[i].sum = it[((i) << 1)].sum + it[(((i) << 1) + 1)].sum;
}
long long get(int i, int l, int r, int u) {
  if (l == r) return (l - 1) * (long long)u;
  if (it[((i) << 1)].sz >= u)
    return get(((i) << 1), l, ((l + r) >> 1), u);
  else
    return it[((i) << 1)].sum +
           get((((i) << 1) + 1), ((l + r) >> 1) + 1, r, u - it[((i) << 1)].sz);
}
int main() {
  ios ::sync_with_stdio(false);
  cin.tie(NULL);
  cout << (fixed) << setprecision(6);
  while (cin >> n >> k) {
    for (int i = 0, _a = (MN); i < _a; i++) {
      cnt[i] = 0;
      ls[i].clear();
    }
    for (int i = (1), _b = (n); i <= _b; i++) {
      cin >> p[i] >> e[i];
      ls[p[i]].push_back(e[i]);
      ls[p[i] + 1].push_back(e[i]);
      cnt[p[i]] += 1;
    }
    for (int i = 0, _a = (MN); i < _a; i++) {
      if (i) cnt[i] += cnt[i - 1];
      sort(ls[i].begin(), ls[i].end());
    }
    memset(it, 0, sizeof it);
    for (int i = (1), _b = (n); i <= _b; i++)
      insert(1, 1, 200001, e[i] + 1, 1, e[i]);
    const long long oo = 1000111000111000111LL;
    long long res = oo;
    for (int win = (0), _b = (n); win <= _b; win++) {
      int better = (win >= 2) ? cnt[win - 2] : 0;
      int need = (n + 1 - k) - better;
      if (need < 0) need = 0;
      if (need > ls[win].size()) continue;
      long long cur = 0;
      for (int x = 0, _a = (need); x < _a; x++) {
        cur += ls[win][x];
        insert(1, 1, 200001, ls[win][x] + 1, -1, -ls[win][x]);
      }
      if (win - need >= 1) cur += get(1, 1, 200001, win - need);
      for (int x = 0, _a = (need); x < _a; x++) {
        insert(1, 1, 200001, ls[win][x] + 1, 1, ls[win][x]);
      }
      res = min(res, cur);
    }
    if (res == oo) res = -1;
    cout << res << endl;
  }
  return 0;
}
