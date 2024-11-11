#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ld = long double;
template <typename T>
vector<T>& operator--(vector<T>& v) {
  for (auto& i : v) --i;
  return v;
}
template <typename T>
vector<T>& operator++(vector<T>& v) {
  for (auto& i : v) ++i;
  return v;
}
template <typename T>
istream& operator>>(istream& is, vector<T>& v) {
  for (auto& i : v) is >> i;
  return is;
}
template <typename T>
ostream& operator<<(ostream& os, vector<T> v) {
  for (auto& i : v) os << i << ' ';
  return os;
}
template <typename T, typename U>
pair<T, U>& operator--(pair<T, U>& p) {
  --p.first;
  --p.second;
  return p;
}
template <typename T, typename U>
pair<T, U>& operator++(pair<T, U>& p) {
  ++p.first;
  ++p.second;
  return p;
}
template <typename T, typename U>
istream& operator>>(istream& is, pair<T, U>& p) {
  is >> p.first >> p.second;
  return is;
}
template <typename T, typename U>
ostream& operator<<(ostream& os, pair<T, U> p) {
  os << p.first << ' ' << p.second;
  return os;
}
template <typename T, typename U>
pair<T, U> operator-(pair<T, U> a, pair<T, U> b) {
  return make_pair(a.first - b.first, a.second - b.second);
}
template <typename T, typename U>
pair<T, U> operator+(pair<T, U> a, pair<T, U> b) {
  return make_pair(a.first + b.first, a.second + b.second);
}
template <typename T, typename U>
void umin(T& a, U b) {
  if (a > b) a = b;
}
template <typename T, typename U>
void umax(T& a, U b) {
  if (a < b) a = b;
}
struct DSU {
  vector<int> rk;
  vector<int> p;
  vector<vector<int>> comp;
  vector<int> col;
  int n;
  DSU(int n = 1) : n(n) { reset(n); }
  void reset(int n) {
    p.resize(n);
    iota(p.begin(), p.end(), 0);
    col.assign(n, 0);
    comp.resize(n);
    for (int i = 0; i < n; ++i) {
      comp[i].push_back(i);
    }
    rk.assign(n, 1);
  }
  int par(int v) { return v == p[v] ? v : p[v] = par(p[v]); }
  bool un(int u, int v) {
    bool need_ch = (col[u] == col[v]);
    u = par(u);
    v = par(v);
    if (u == v) return false;
    if (rk[u] > rk[v]) swap(u, v);
    p[u] = v;
    rk[v] += rk[u];
    for (int k : comp[u]) {
      comp[v].push_back(k);
      if (need_ch) col[k] ^= 1;
    }
    return true;
  }
  bool check(int u, int v) { return par(u) == par(v); }
  bool is_same(int u, int v) { return check(u, v) && col[u] == col[v]; }
  bool is_dif(int u, int v) { return check(u, v) && col[u] != col[v]; }
};
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  int n, m;
  cin >> n >> m;
  vector<string> v(n);
  cin >> v;
  vector<int> nei;
  vector<int> nei2;
  DSU d(n * m);
  auto conn = [&](int u, int v) {
    if (d.is_same(u, v)) {
      cout << "NO\n";
      exit(0);
    }
    d.un(u, v);
  };
  queue<pair<int, int>> fours;
  for (int i = 0; i < n; ++i) {
    for (int j = 0; j < m; ++j) {
      if (v[i][j] == 'X') {
        nei.clear();
        if (v[i - 1][j] != 'X') nei.push_back((i - 1) * m + j);
        if (v[i + 1][j] != 'X') nei.push_back((i + 1) * m + j);
        if (v[i][j - 1] != 'X') nei.push_back(i * m + j - 1);
        if (v[i][j + 1] != 'X') nei.push_back(i * m + j + 1);
        if (nei.size() % 2 != 0) {
          cout << "NO\n";
          return 0;
        }
        if (nei.empty()) continue;
        if (nei.size() == 2) {
          conn(nei[0], nei[1]);
        } else {
          fours.emplace(i, j);
        }
      }
    }
  }
  vector<vector<bool>> u(n, vector<bool>(m, false));
  int unch = 0;
  while (!fours.empty()) {
    auto [i, j] = fours.front();
    fours.pop();
    nei.clear();
    if (v[i - 1][j] != 'X') nei.push_back((i - 1) * m + j);
    if (v[i + 1][j] != 'X') nei.push_back((i + 1) * m + j);
    if (v[i][j - 1] != 'X') nei.push_back(i * m + j - 1);
    if (v[i][j + 1] != 'X') nei.push_back(i * m + j + 1);
    if (nei.size() != 4) continue;
    bool found = false;
    for (int i = 0; i < nei.size(); ++i) {
      for (int j = 0; j < i; ++j) {
        if (d.is_dif(nei[i], nei[j])) {
          found = true;
          nei2.clear();
          for (int k = 0; k < nei.size(); ++k) {
            if (k == i || k == j) continue;
            nei2.push_back(nei[k]);
          }
          conn(nei2[0], nei2[1]);
          break;
        } else if (d.is_same(nei[i], nei[j])) {
          found = true;
          nei2.clear();
          for (int k = 0; k < nei.size(); ++k) {
            if (k == i || k == j) continue;
            nei2.push_back(nei[k]);
          }
          conn(nei[i], nei2[0]);
          conn(nei[i], nei2[1]);
          conn(nei[j], nei2[0]);
          conn(nei[j], nei2[1]);
          break;
        }
      }
      if (found) break;
    }
    if (found) {
      unch = 0;
      continue;
    }
    if (unch >= fours.size() || unch >= 505) {
      conn(nei[0], nei[2]);
      conn(nei[1], nei[3]);
      unch = 0;
    } else {
      ++unch;
      fours.emplace(i, j);
    }
  }
  vector<vector<int>> ans(n, vector<int>(m));
  for (int i = 0; i < n; ++i) {
    for (int j = 0; j < m; ++j) {
      if (v[i][j] == '.') ans[i][j] = (d.col[i * m + j] ? 1 : 4);
    }
  }
  for (int i = 0; i < n; ++i) {
    for (int j = 0; j < m; ++j) {
      if (v[i][j] == 'X') {
        nei.clear();
        if (v[i - 1][j] != 'X') nei.push_back((i - 1) * m + j);
        if (v[i + 1][j] != 'X') nei.push_back((i + 1) * m + j);
        if (v[i][j - 1] != 'X') nei.push_back(i * m + j - 1);
        if (v[i][j + 1] != 'X') nei.push_back(i * m + j + 1);
        for (int k : nei) ans[i][j] += (d.col[k] ? 1 : 4);
        if (ans[i][j] % 5 != 0) {
          cout << "NO\n";
          return 0;
        }
      }
    }
  }
  cout << "YES\n";
  for (auto& l : ans) cout << l << '\n';
  return 0;
}
