#include <bits/stdc++.h>
#pragma comment(linker, "/STACK:216000000")
using namespace std;
const long long MAX = 100000000LL * 100000000LL;
const long long MIN = numeric_limits<long long>::min();
const double PI = 3.14159265358979;
const long long MOD = 1000000007LL;
template <class T>
ostream& operator<<(ostream& out, vector<T>& v) {
  for (int i = 0; i < v.size(); ++i) out << v[i] << " ";
  return out;
}
template <class T>
istream& operator>>(istream& in, vector<T>& v) {
  for (int i = 0; i < v.size(); ++i) in >> v[i];
  return in;
}
template <class L, class R>
istream& operator>>(istream& in, pair<L, R>& p) {
  in >> p.first >> p.second;
  return in;
}
template <class T>
T lexical_cast(string& s) {
  stringstream ss(s);
  T t;
  ss >> t;
  return t;
}
long long gcd(long long a, long long b) { return b ? gcd(b, a % b) : a; }
long long cdiv(long long a, long long b) { return (a + b - 1) / b; }
long long inv(long long n, long long mod) {
  long long pow = mod - 2;
  long long ans = 1;
  long long cur = n;
  while (pow > 0) {
    if (pow & 1) {
      ans *= cur;
      ans %= mod;
    }
    pow /= 2;
    cur *= cur;
    cur %= mod;
  }
  return ans;
}
template <class Cont>
void sort(Cont& c) {
  sort(begin(c), end(c));
}
template <class Cont>
void reverse(Cont& c) {
  reverse(begin(c), end(c));
}
bool dfs(int v, int p, vector<vector<pair<int, long long>>>& G,
         vector<int>& color, vector<int>& pr, int& st, int& end,
         vector<long long>& l) {
  color[v] = 1;
  for (auto el : G[v]) {
    if (el.first == p) continue;
    l[v] = el.second;
    int to = el.first;
    if (color[to] == 0) {
      pr[v] = to;
      if (dfs(to, v, G, color, pr, st, end, l)) {
        return true;
      }
    } else if (color[to] == 1) {
      end = v;
      st = to;
      return true;
    }
  }
  color[v] = 2;
  return false;
}
long long dfs1(int v, int p, vector<vector<pair<int, long long>>>& G,
               vector<bool>& cycle) {
  long long d = 0;
  for (auto el : G[v]) {
    int to = el.first;
    if (to != p && !cycle[to]) {
      d = max(d, el.second + dfs1(to, v, G, cycle));
    }
  }
  return d;
}
pair<int, long long> farest(int v, int p,
                            vector<vector<pair<int, long long>>>& G) {
  pair<int, long long> ans = {v, 0};
  for (auto el : G[v]) {
    int to = el.first;
    if (to != p) {
      auto par = farest(to, v, G);
      if (par.second + el.second > ans.second) {
        ans = par;
        ans.second += el.second;
      }
    }
  }
  return ans;
}
int main() {
  ios_base::sync_with_stdio(false), cin.tie(0), cout.tie(0);
  int n, m;
  cin >> n >> m;
  vector<vector<char>> f(n, vector<char>(m));
  for (int i = 0; i < n; ++i) {
    for (int j = 0; j < m; ++j) {
      cin >> f[i][j];
    }
  }
  if (n % 3 == 0) {
    char ci[3] = {f[0][0], f[n / 3][0], f[2 * n / 3][0]};
    if (ci[0] != ci[1] && ci[0] != ci[2] && ci[1] != ci[2]) {
      bool ok = true;
      for (int c = 0; c < 2; ++c) {
        for (int i = 0; i < n / 3; ++i) {
          for (int j = 0; j < m; ++j) {
            if (f[c * n / 3 + i][j] != ci[c]) ok = false;
          }
        }
      }
      if (ok) {
        cout << "YES";
        return 0;
      }
    }
  }
  if (m % 3 == 0) {
    char ci[3] = {f[0][0], f[0][m / 3], f[0][2 * m / 3]};
    if (ci[0] != ci[1] && ci[0] != ci[2] && ci[1] != ci[2]) {
      bool ok = true;
      for (int c = 0; c < 2; ++c) {
        for (int i = 0; i < n; ++i) {
          for (int j = 0; j < m / 3; ++j) {
            if (f[i][c * m / 3 + j] != ci[c]) ok = false;
          }
        }
      }
      if (ok) {
        cout << "YES";
        return 0;
      }
    }
  }
  cout << "NO";
}
