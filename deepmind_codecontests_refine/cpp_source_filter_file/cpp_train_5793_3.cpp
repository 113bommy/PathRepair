#include <bits/stdc++.h>
#pragma comment(linker, "/stack:200000000")
#pragma GCC optimize("Ofast")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")
using namespace std;
int ni() {
  int val;
  scanf("%i", &val);
  return val;
}
pair<int, int> npi() {
  pair<int, int> val;
  scanf("%i %i", &val.first, &val.second);
  return val;
}
int64_t nll() {
  int64_t val;
  scanf("%I64d", &val);
  return val;
}
vector<int> nvi(int n, int corr = 0) {
  vector<int> a(n);
  for (int i = 0; i < n; ++i) a[i] = ni() + corr;
  return move(a);
}
char nc() {
  char val;
  do {
    val = getchar();
  } while (val == ' ' || val == '\r' || val == '\n');
  return val;
}
char ncs() {
  char val;
  do {
    val = getchar();
  } while (false);
  return val;
}
string ns() {
  static char buff[1024 * 4000];
  scanf("%s", buff);
  return string{buff};
}
int64_t gcd(int64_t a, int64_t b) {
  while (b) {
    auto tmp = a % b;
    a = b;
    b = tmp;
  }
  return a;
}
int64_t tr2(int xv1, int yv1, int xv2, int yv2, int x3, int y3) {
  return 1LL * (xv2 - xv1) * (y3 - yv1) - 1LL * (yv2 - yv1) * (x3 - xv1);
}
const long double eps = 1e-12;
const long double pi = acos(-1.0);
bool eq(long double a, long double b) { return abs(a - b) <= eps; }
int8_t bits_cnt[256];
const string input_dir = "inputs\\";
string input_file = input_dir + "input.txt";
string output_file = input_dir + "output.txt";
void init_streams() {}
void init_data() {
  for (int i = 1; i <= 255; ++i)
    for (int j = 0; j < 8; ++j)
      if ((1 << j) & i) ++bits_cnt[i];
}
int bit_count(int v) {
  return bits_cnt[v & 0xFF] + bits_cnt[(v >> 8) & 0xFF] +
         bits_cnt[(v >> 16) & 0xFF] + bits_cnt[(v >> 24) & 0xFF];
}
const int maxn = 24;
const int inf = 1000;
int8_t g[maxn][maxn];
int8_t ng[maxn][maxn];
pair<int, int> get_maxd(int n) {
  int max_d = 0, v = 0;
  vector<int> vs(n);
  for (int i = 0; i < n; ++i) vs[i] = i;
  random_shuffle((vs).begin(), (vs).end());
  for (int q = 0; q < n; ++q) {
    auto i = vs[q];
    vector<bool> used(n);
    vector<int> d(n, inf);
    d[i] = 0;
    used[i] = 1;
    queue<int> que;
    que.push(i);
    while (!que.empty()) {
      auto cur = que.front();
      que.pop();
      for (int j = 0; j < n; ++j)
        if (g[cur][j]) {
          if (!used[j]) {
            que.push(j);
            d[j] = d[cur] + 1;
            used[j] = 1;
          }
        }
    }
    auto dm = *max_element((d).begin(), (d).end());
    if (dm > max_d) {
      max_d = dm;
      v = i;
    }
  }
  return make_pair(max_d, v);
}
bool apply(int n, const vector<int>& src) {
  memcpy(ng, g, sizeof(g));
  vector<int> flist;
  for (auto s : src) {
    flist.clear();
    flist.push_back(s);
    for (int j = 0; j < n; ++j)
      if (ng[s][j]) flist.push_back(j);
    for (int j = 0; j < flist.size(); ++j)
      for (int k = j + 1; k < flist.size(); ++k) {
        ng[flist[j]][flist[k]] = 1;
        ng[flist[k]][flist[j]] = 1;
      }
  }
  vector<bitset<32>> adj(n);
  for (int i = 0; i < n; ++i)
    for (int j = 0; j < n; ++j) {
      if (i != j && ng[i][j]) adj[i].set(j);
    }
  if (all_of((adj).begin(), (adj).end(),
             [n](const bitset<32>& ad) { return ad.count() + 1 == n; }))
    return true;
  return false;
}
int main() {
  init_streams();
  init_data();
  auto n = ni(), m = ni();
  for (int i = 0; i < m; ++i) {
    auto a = ni() - 1, b = ni() - 1;
    g[a][b] = g[b][a] = 1;
  }
  vector<int> lst;
  vector<int> ans0;
  for (int mask = 0; mask < (1 << n); ++mask) {
    if (bit_count(mask) <= 4) {
      lst.clear();
      for (int j = 0; j < n; ++j)
        if ((1 << j) & mask) {
          lst.push_back(j);
        }
      if (apply(n, lst)) {
        if (ans0.empty() || lst.size() < ans0.size()) {
          ans0 = lst;
        }
      }
    }
  }
  vector<int> ans;
  auto dd = get_maxd(n);
  while (dd.first > 1) {
    vector<bool> used(n);
    vector<int> d(n, inf);
    vector<int> p(n, -1);
    d[dd.second] = 0;
    used[dd.second] = 1;
    queue<int> que;
    que.push(dd.second);
    int maxd = 0, vd = 0;
    while (!que.empty()) {
      auto cur = que.front();
      que.pop();
      for (int j = n - 1; j >= 0; --j)
        if (g[cur][j]) {
          if (!used[j]) {
            used[j] = 1;
            que.push(j);
            p[j] = cur;
            d[j] = d[cur] + 1;
            if (d[j] > maxd) {
              maxd = d[j];
              vd = j;
            }
          }
        }
    }
    vector<int> path{vd};
    do {
      vd = p[vd];
      path.push_back(vd);
    } while (vd != dd.second);
    vector<pair<int, int>> changes;
    for (int i = 1; i + 1 < path.size(); ++i) {
      ans.push_back(path[i]);
      vector<int> flist{path[i]};
      for (int j = 0; j < n; ++j)
        if (g[path[i]][j]) flist.push_back(j);
      for (int j = 0; j < flist.size(); ++j)
        for (int k = 0; k < flist.size(); ++k)
          if (j != k) {
            g[flist[j]][flist[k]] = 1;
            g[flist[k]][flist[j]] = 1;
          }
    }
    dd = get_maxd(n);
  }
  if (!ans0.empty() && ans0.size() < ans.size()) ans = ans0;
  cout << ans.size() << endl;
  for (auto v : ans) cout << v + 1 << " ";
  return 0;
}
