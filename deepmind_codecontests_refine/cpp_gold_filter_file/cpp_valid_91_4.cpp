#include <bits/stdc++.h>
using namespace std;
const int maxn = 1e5 + 5;
const int logn = 20;
const int mod = 998244353;
struct edge {
  int u, v, w;
};
vector<edge> vec;
struct cmp {
  bool operator()(int a, int b) const {
    return vec[a].w < vec[b].w || (vec[a].w == vec[b].w && a < b);
  }
};
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  if (fopen("A"
            ".INP",
            "r")) {
    freopen(
        "A"
        ".INP",
        "r", stdin);
    freopen(
        "A"
        ".OUT",
        "w", stdout);
  }
  int n, m;
  cin >> n >> m;
  vec.resize(m);
  multiset<long long> s;
  set<int, cmp> alls;
  vector<int> cnt(maxn * 2, 0);
  vector<set<int, cmp>> adj(n);
  auto get_adj = [&](int u) -> vector<edge> {
    vector<edge> tmp;
    auto it = adj[u].begin();
    for (int i = 0; i < 3 && it != adj[u].end(); ++i) {
      tmp.push_back(vec[*it]);
      ++it;
    }
    return tmp;
  };
  auto get_sum = [&](int u) {
    auto tmp = get_adj(u);
    long long sum = 0;
    for (auto& c : tmp) sum += c.w;
    return sum;
  };
  auto add = [&](int u, int e) {
    auto it = adj[u].begin();
    for (int i = 0; i < 3 && it != adj[u].end(); ++i) {
      if (cnt[*it]-- == 1) alls.erase(*it);
      ++it;
    }
    if (adj[u].size() >= 3) s.erase(s.find(get_sum(u)));
    adj[u].insert(e);
    if (adj[u].size() >= 3) s.insert(get_sum(u));
    it = adj[u].begin();
    for (int i = 0; i < 3 && it != adj[u].end(); ++i) {
      if (cnt[*it]++ == 1) alls.insert(*it);
      ++it;
    }
  };
  auto del = [&](int u, int e) {
    auto it = adj[u].begin();
    for (int i = 0; i < 3 && it != adj[u].end(); ++i) {
      if (cnt[*it]-- == 1) alls.erase(*it);
      ++it;
    }
    if (adj[u].size() >= 3) s.erase(s.find(get_sum(u)));
    adj[u].erase(e);
    if (adj[u].size() >= 3) s.insert(get_sum(u));
    it = adj[u].begin();
    for (int i = 0; i < 3 && it != adj[u].end(); ++i) {
      if (cnt[*it]++ == 1) alls.insert(*it);
      ++it;
    }
  };
  map<pair<int, int>, int> mmap;
  for (int i = 0; i < m; ++i) {
    cin >> vec[i].u >> vec[i].v >> vec[i].w;
    if (vec[i].u > vec[i].v) swap(vec[i].u, vec[i].v);
    --vec[i].u;
    --vec[i].v;
    add(vec[i].u, i);
    add(vec[i].v, i);
    mmap[make_pair(vec[i].u, vec[i].v)] = mmap[make_pair(vec[i].v, vec[i].u)] =
        i;
  }
  auto calres = [&]() {
    long long res = (s.size() ? *s.begin() : 3e9);
    int id = *alls.begin();
    {
      auto it = alls.begin();
      for (int i = 0;; ++i) {
        ++it;
        if (it == alls.end()) break;
        int j = *it;
        if (vec[id].u != vec[j].u && vec[id].u != vec[j].v &&
            vec[id].v != vec[j].u && vec[id].v != vec[j].v) {
          res = min(res, 0ll + vec[id].w + vec[j].w);
          break;
        }
      }
    }
    auto a = get_adj(vec[id].u), b = get_adj(vec[id].v);
    for (auto& [u, v, w] : a) {
      for (auto& [u1, v1, w1] : b) {
        if (u != u1 && v != v1 && u != v1 && v != u1)
          res = min(res, 0ll + w + w1);
      }
    }
    return res;
  };
  cout << calres() << '\n';
  int q;
  cin >> q;
  while (q--) {
    int type;
    cin >> type;
    if (type == 1) {
      int u, v, c;
      cin >> u >> v >> c;
      --u;
      --v;
      if (u > v) swap(u, v);
      int i = vec.size();
      vec.push_back({u, v, c});
      add(u, i);
      add(v, i);
      mmap[make_pair(u, v)] = mmap[make_pair(v, u)] = i;
    } else {
      int u, v;
      cin >> u >> v;
      --u;
      --v;
      del(u, mmap[make_pair(u, v)]);
      del(v, mmap[make_pair(u, v)]);
      assert(alls.find(mmap[make_pair(u, v)]) == alls.end());
    }
    cout << calres() << '\n';
  }
}
