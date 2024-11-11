#include <bits/stdc++.h>
using namespace std;
template <typename TH>
void _dbg(const char* sdbg, TH h) {
  cerr << sdbg << "=" << h << "\n";
}
template <typename TH, typename... TA>
void _dbg(const char* sdbg, TH h, TA... t) {
  while (*sdbg != ',') {
    cerr << *sdbg++;
  }
  cerr << "=" << h << ",";
  _dbg(sdbg + 1, t...);
}
template <class C>
void mini(C& a4, C b4) {
  a4 = min(a4, b4);
}
template <class C>
void maxi(C& a4, C b4) {
  a4 = max(a4, b4);
}
template <class T1, class T2>
ostream& operator<<(ostream& out, pair<T1, T2> pair) {
  return out << "(" << pair.first << ", " << pair.second << ")";
}
template <class A, class B, class C>
struct Triple {
  A first;
  B second;
  C third;
  bool operator<(const Triple& t) const {
    if (first != t.first) return first < t.first;
    if (second != t.second) return second < t.second;
    return third < t.third;
  }
};
template <class T>
void ResizeVec(T&, vector<int>) {}
template <class T>
void ResizeVec(vector<T>& vec, vector<int> sz) {
  vec.resize(sz[0]);
  sz.erase(sz.begin());
  if (sz.empty()) {
    return;
  }
  for (T& v : vec) {
    ResizeVec(v, sz);
  }
}
template <class A, class B, class C>
ostream& operator<<(ostream& out, Triple<A, B, C> t) {
  return out << "(" << t.first << ", " << t.second << ", " << t.third << ")";
}
template <class T>
ostream& operator<<(ostream& out, vector<T> vec) {
  out << "(";
  for (auto& v : vec) out << v << ", ";
  return out << ")";
}
template <class T>
ostream& operator<<(ostream& out, set<T> vec) {
  out << "(";
  for (auto& v : vec) out << v << ", ";
  return out << ")";
}
template <class L, class R>
ostream& operator<<(ostream& out, map<L, R> vec) {
  out << "(";
  for (auto& v : vec) out << v << ", ";
  return out << ")";
}
const int M = 1 << 17;
vector<vector<int> > cycles;
vector<pair<int, int> > stos;
vector<pair<int, int> > slo[M];
int vis[M];
int d;
int pre[M];
void Dfs(int v) {
  vis[v] = 1;
  pre[v] = d++;
  for (auto e : slo[v]) {
    int nei = e.first;
    int w = e.second;
    if (vis[nei]) {
      if (((int)(stos).size()) >= 2 &&
          stos[((int)(stos).size()) - 2].first == nei) {
        continue;
      }
      if (pre[nei] > pre[v]) {
        continue;
      }
      (nei, v);
      cycles.push_back(vector<int>{w});
      for (int ind = (((int)(stos).size()) - 1); ind >= (0); --ind) {
        if (stos[ind].first == nei) {
          break;
        }
        cycles.back().push_back(stos[ind].second);
      }
      continue;
    }
    stos.push_back({nei, w});
    Dfs(nei);
    stos.pop_back();
  }
}
int MOD = 1e9 + 7;
const int M2 = 999999197;
const int INV2 = (MOD + 1) / 2;
void SelfMod(int& a) {
  while (a >= MOD) {
    a -= MOD;
  }
}
void Dziel(int& a) {
  if (a % 2 == 0) {
    a /= 2;
  } else {
    a = (a + MOD) / 2;
  }
}
void transform(int x, int y, int* a) {
  if (x == y - 1) {
    return;
  }
  int l2 = (y - x) / 2;
  int z = x + l2;
  transform(x, z, a);
  transform(z, y, a);
  for (int i = x; i < z; i++) {
    int x1 = a[i];
    int x2 = a[i + l2];
    a[i] = (x1 - x2 + MOD);
    a[i + l2] = (x1 + x2);
    SelfMod(a[i]);
    SelfMod(a[i + l2]);
  }
}
void untransform(int x, int y, int* a) {
  if (x == y - 1) {
    return;
  }
  int l2 = (y - x) / 2;
  int z = x + l2;
  for (int i = x; i < z; i++) {
    long long y1 = a[i];
    long long y2 = a[i + l2];
    a[i] = (y1 + y2);
    a[i + l2] = (y2 - y1 + MOD);
    SelfMod(a[i]);
    SelfMod(a[i + l2]);
    Dziel(a[i]);
    Dziel(a[i + l2]);
  }
  untransform(x, z, a);
  untransform(z, y, a);
}
int32_t main() {
  ios_base::sync_with_stdio(0);
  cout << fixed << setprecision(10);
  if (0) cout << fixed << setprecision(10);
  cin.tie(0);
  int n, m;
  cin >> n >> m;
  int xorr = 0;
  for (int i = (1); i <= (m); ++i) {
    int a, b, w;
    cin >> a >> b >> w;
    xorr ^= w;
    slo[a].push_back({b, w});
    slo[b].push_back({a, w});
  }
  stos.push_back({1, 0});
  Dfs(1);
  (cycles);
  vector<int> cur(M), cur2(M);
  cur[0] = 1;
  transform(0, M, &cur[0]);
  MOD = M2;
  cur2[0] = 1;
  transform(0, M, &cur2[0]);
  for (auto cycle : cycles) {
    vector<int> cyc_cnt(M);
    for (auto x : cycle) {
      cyc_cnt[x]++;
    }
    MOD = 1e9 + 7;
    transform(0, M, &cyc_cnt[0]);
    for (int i = 0; i < (M); ++i) {
      cur[i] = 1ll * cur[i] * cyc_cnt[i] % MOD;
    }
    for (int i = 0; i < (M); ++i) {
      cyc_cnt[i] = 0;
    }
    for (auto x : cycle) {
      cyc_cnt[x]++;
    }
    MOD = M2;
    transform(0, M, &cyc_cnt[0]);
    for (int i = 0; i < (M); ++i) {
      cur2[i] = 1ll * cur2[i] * cyc_cnt[i] % MOD;
    }
  }
  int min_res = 1e9;
  int wh_min = -1;
  MOD = 1e9 + 7;
  untransform(0, M, &cur[0]);
  MOD = M2;
  untransform(0, M, &cur2[0]);
  if (n < 45) {
    assert(cur == cur2);
  }
  for (int i = 0; i < (M); ++i) {
    if (cur[i] || cur2[i]) {
      int cand_xor = xorr ^ i;
      if (cand_xor < min_res) {
        min_res = cand_xor;
        wh_min = i;
      }
    }
  }
  cout << min_res << " " << cur[wh_min] << "\n";
  return 0;
}
