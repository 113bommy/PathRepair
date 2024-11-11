#include <bits/stdc++.h>
using namespace std;
const int INF = (int)1.1e9;
const int maxN = 1 << 18;
struct SegTree {
  vector<int> T;
  SegTree() { T = vector<int>(2 * maxN, -INF); }
  void upd(int v, int x) {
    for (v += maxN; v; v /= 2) {
      T[v] = max(T[v], x);
    }
  }
  int get(int l, int r) {
    int ans = -INF;
    for (l += maxN, r += maxN; l <= r; l /= 2, r /= 2) {
      if (l % 2 == 1) ans = max(T[l], ans);
      if (r % 2 == 0) ans = max(T[r], ans);
      l++, r--;
    }
    return ans;
  }
};
int s[maxN], f[maxN], t[maxN], rev[maxN], ans[maxN];
vector<pair<int, int> > modif[maxN];
vector<pair<pair<int, int>, int> > ask[maxN];
int main() {
  map<int, int> ms;
  map<int, int> mt;
  int n, q;
  scanf("%d%d", &n, &q);
  for (int i = 0; i < n + q; i++) {
    scanf("%d%%d%d", &s[i], &f[i], &t[i]);
    mt[t[i]];
    ms[s[i]];
  }
  int i;
  i = 0;
  for (auto x : ms) {
    ms[x.first] = i++;
  }
  i = 0;
  for (auto x : mt) {
    mt[x.first] = i++;
  }
  for (int i = 0; i < n + q; i++) {
    s[i] = ms[s[i]];
    t[i] = mt[t[i]];
    if (i < n) {
      modif[s[i]].push_back({t[i], f[i]});
      rev[t[i]] = i + 1;
    } else {
      ask[s[i]].push_back({{t[i], f[i]}, i - n});
    }
  }
  SegTree T;
  T.upd(mt.size(), INF);
  rev[mt.size()] = -1;
  for (int i = 0; i < ms.size(); i++) {
    for (auto x : modif[i]) {
      T.upd(x.first, x.second);
    }
    for (auto x : ask[i]) {
      int l = x.first.first - 1, r = mt.size();
      while (r - l > 1) {
        int m = (r + l) / 2;
        if (T.get(x.first.first, m) >= x.first.second) {
          r = m;
        } else {
          l = m;
        }
      }
      ans[x.second] = rev[r];
    }
  }
  for (int i = 0; i < q; i++) {
    printf("%d\n", ans[i]);
  }
  printf("\n");
  return 0;
}
