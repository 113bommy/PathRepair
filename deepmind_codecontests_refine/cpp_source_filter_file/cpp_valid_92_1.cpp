#include <bits/stdc++.h>
using namespace std;
const long long INFLL = 1e18;
const int INF = 1e9 + 1;
const int MAXC = 1e6;
mt19937 gen(time(0));
vector<int> e(MAXC + 5);
void precalc() {
  vector<int> p;
  for (int i = 2; i <= MAXC; i++) {
    if (e[i] == 0) {
      e[i] = i;
      p.emplace_back(i);
    }
    for (int j = 0; j < (int)p.size() && p[j] * i <= MAXC && p[j] <= e[i];
         j++) {
      e[p[j] * i] = p[j];
    }
  }
}
int f(int x) {
  int ans = 1;
  vector<int> p;
  while (x > 1) {
    p.emplace_back(e[x]);
    x /= e[x];
  }
  for (int i = 0; i < (int)p.size(); i++) {
    if (i + 1 == (int)p.size() || p[i + 1] != p[i]) ans *= p[i];
  }
  return ans;
}
void gauss(int need, vector<int> &lst, vector<int> &ans,
           vector<vector<int>> &sz, vector<vector<vector<int>>> &v) {
  int n = lst.size();
  vector<bitset<20>> a(n);
  for (int i = 0; i < n; i++) a[i] = lst[i];
  bitset<20> b = need;
  vector<bitset<30>> l(n);
  for (int i = 0; i < n; i++) l[i][i] = 1;
  int i = 0;
  vector<int> col(20, -1);
  int bas_sz = 0;
  for (int j = 0; j < 20 && i < n; j++) {
    int i1 = i;
    while (i1 < n && a[i1][j] == 0) i1++;
    if (i1 == n) continue;
    swap(a[i], a[i1]);
    swap(l[i], l[i1]);
    bas_sz++;
    col[j] = i;
    for (int i2 = i + 1; i2 < n; i2++) {
      if (a[i2][j]) {
        a[i2] ^= a[i];
        l[i2] ^= l[i];
      }
    }
    i++;
  }
  bitset<20> res;
  bitset<30> path;
  for (int j = 0; j < 20; j++) {
    if (res[j] != b[j] && col[j] == -1) {
      exit(0);
    }
    if (res[j] == b[j]) continue;
    res ^= a[col[j]];
    path ^= l[col[j]];
  }
  if (a.back().count() != 0) {
    for (int i = 0; i < n; i++) {
      if (path[i]) ans.emplace_back(lst[i]);
    }
    return;
  }
  vector<int> diff_sz(30);
  sz.emplace_back();
  v.emplace_back();
  for (int it = 0; it < 100; it++) {
    bitset<30> now = path;
    for (int i = 0; i < n - bas_sz; i++) {
      if (gen() % 2) now ^= l[bas_sz + i];
    }
    int now_sz = now.count();
    if (diff_sz[now_sz]) continue;
    v.back().emplace_back();
    for (int i = 0; i < n; i++) {
      if (now[i]) v.back().back().emplace_back(lst[i]);
    }
    diff_sz[now_sz] = 1;
    sz.back().emplace_back(now_sz);
  }
}
vector<int> mem(2 * MAXC + 5, -1);
int query(int x) { return mem[f(x)]; }
void solve(int n, int c) {
  vector<int> calc(c + 1);
  vector<vector<int>> total(c + 1);
  for (int x = 1; x <= c; x++) total[f(x)].emplace_back(x);
  vector<int> need;
  for (int x = 1; x <= c; x++) {
    if (total[x].size()) need.emplace_back(x);
  }
  cout << need.size() << " ";
  for (auto &c : need) cout << c << " ";
  cout << endl;
  for (auto &c : need) {
    int x;
    cin >> x;
    mem[c] = x;
  }
  int total_xor = query(1);
  for (int x = 1; x <= c; x++) {
    if (total[x].empty()) continue;
    for (int y = x; y <= c; y += x) calc[y] ^= (query(x) ^ total_xor);
  }
  calc[1] = total_xor;
  for (int x = c; x >= 1; x--) {
    if (total[x].empty()) continue;
    for (int y = 2 * x; y <= c; y += x) {
      if (total[y].size()) calc[x] ^= calc[y];
    }
  }
  vector<int> ans;
  vector<vector<int>> sz;
  vector<vector<vector<int>>> v;
  for (int x = 1; x <= c; x++) {
    if (total[x].empty()) continue;
    gauss(calc[x], total[x], ans, sz, v);
  }
  vector<bitset<40000>> bag(sz.size() + 1);
  bag[0][0] = 1;
  for (int i = 1; i <= (int)sz.size(); i++) {
    for (auto &x : sz[i - 1]) {
      bag[i] |= (bag[i - 1] << x);
    }
  }
  int now = n - ans.size();
  for (int i = (int)sz.size(); i >= 1; i--) {
    for (int j = 0; j < (int)sz[i - 1].size(); j++) {
      int x = sz[i - 1][j];
      if (now - x >= 0 && bag[i - 1][now - x]) {
        now -= x;
        for (auto &y : v[i - 1][j]) ans.emplace_back(y);
        break;
      }
    }
  }
  sort((ans).begin(), (ans).end());
  for (auto &c : ans) cout << c << " ";
  cout << endl;
}
int main() {
  precalc();
  int c, n;
  cin >> c >> n;
  solve(n, c);
  return 0;
}
