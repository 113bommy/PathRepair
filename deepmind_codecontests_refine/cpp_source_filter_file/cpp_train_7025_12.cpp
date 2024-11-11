#include <bits/stdc++.h>
using namespace std;
#pragma GCC optimize("Ofast")
const int maxn = 5e5 + 10, N = 500 + 10, SQRT = 300, base = 800287,
          mod = 1e9 + 7, INF = 1e9 + 1, lg = 18;
const long double eps = 1e-4;
long long res[maxn];
int n, q, SA[maxn], suffix_num[maxn], pos[maxn], sz[maxn];
int mn[maxn][lg], fen[maxn], Rank[maxn][lg];
vector<pair<int, pair<int, int>>> vec[maxn], curr;
string t;
inline int lcp(int a, int b) {
  int res = 0;
  for (int i = lg - 1; i >= 0; --i) {
    if (Rank[a][i] == Rank[b][i]) {
      res += (1ll << i);
      a += (1ll << i);
      b += (1ll << i);
    }
  }
  return res;
}
bool cmp(pair<int, pair<int, int>> a, pair<int, pair<int, int>> b) {
  if (a.second.first != b.second.first) {
    return a.second.first < b.second.first;
  }
  return a.second.second < b.second.second;
}
inline void build_suffixarray() {
  for (int i = 0; i < (int)t.size(); ++i) {
    if (t[i] == '#') {
      Rank[i][0] = INF;
    } else {
      Rank[i][0] = (int)(t[i] - 'a');
    }
  }
  for (int i = 1; i < lg; ++i) {
    curr.clear();
    for (int j = 0; j < (int)t.size(); ++j) {
      int val = (j + (1ll << (i - 1)) < (int)t.size()
                     ? Rank[j + (1ll << (i - 1))][i - 1]
                     : -INF);
      curr.push_back({j, {Rank[j][i - 1], val}});
    }
    sort(curr.begin(), curr.end(), cmp);
    int id = 0;
    Rank[curr[0].first][i] = 0;
    for (int j = 1; j < (int)t.size(); ++j) {
      if (curr[j].second != curr[j - 1].second) {
        id++;
      }
      Rank[curr[j].first][i] = id;
    }
  }
  for (int i = 0; i < (int)t.size(); ++i) {
    SA[Rank[i][lg - 1]] = i;
  }
  for (int i = 0; i < (int)t.size(); ++i) {
    pos[SA[i]] = i;
  }
}
inline void add(int p) {
  for (p++; p < maxn; p += (p & -p)) {
    fen[p]++;
  }
}
inline int get(int p) {
  int res = 0;
  if (!p) {
    return 0;
  }
  for (; p; p -= (p & -p)) {
    res += fen[p];
  }
  return res;
}
char tmp[maxn];
int32_t main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  scanf("%d%d", &n, &q);
  for (int i = 0; i < n; ++i) {
    scanf("%s", tmp);
    sz[i] = strlen(tmp);
    suffix_num[i] = (int)t.size();
    t += tmp;
    t += '#';
  }
  build_suffixarray();
  for (int i = 0; i < lg; ++i) {
    for (int j = 0; j < (int)t.size(); ++j) {
      if (!i && pos[j] + 1 < (int)t.size()) {
        mn[pos[j]][i] = lcp(SA[pos[j]], SA[pos[j] + 1]);
      } else if (pos[j] + (1ll << (i - 1)) < (int)t.size()) {
        mn[pos[j]][i] =
            min(mn[pos[j]][i - 1], mn[pos[j] + (1ll << (i - 1))][i - 1]);
      } else {
        mn[pos[j]][i] = mn[pos[j]][i - 1];
      }
    }
  }
  for (int i = 0; i < q; ++i) {
    int l, r, k;
    scanf("%d%d%d", &l, &r, &k);
    l--;
    r--;
    k--;
    if (l - 1 >= 0) {
      vec[l - 1].push_back({-1, {i, k}});
    }
    vec[r].push_back({1, {i, k}});
  }
  int id = 0;
  for (int i = 0; i < n; ++i) {
    for (int j = id; j <= id + sz[i]; ++j) {
      add(pos[j]);
    }
    id += sz[i] + 1;
    for (auto u : vec[i]) {
      int type = u.first, idx = u.second.first, p = u.second.second;
      int l = pos[suffix_num[p]], r = pos[suffix_num[p]];
      for (int i = lg - 1; i >= 0; --i) {
        if (mn[r][i] >= sz[p] && r + (1ll << i) < (int)t.size()) {
          r = r + (1ll << i);
        }
      }
      for (int i = lg - 1; i >= 0; --i) {
        if (l - (1ll << i) >= 0 && mn[l - (1ll << i)][i] >= sz[p]) {
          l = l - (1ll << i);
        }
      }
      int val = get(r + 1) - get(l);
      res[idx] += type * val;
    }
  }
  for (int i = 0; i < q; ++i) {
    printf("%lld\n", res[i]);
  }
}
