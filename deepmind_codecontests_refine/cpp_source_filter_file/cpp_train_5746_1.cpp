#include <bits/stdc++.h>
using namespace std;
const int M = 1000000007;
const int MM = 998244353;
const long double PI = acos(-1);
long long power(long long b, long long e, long long m) {
  if (e == 0) return 1;
  if (e & 1) return b * power(b * b % m, e / 2, m) % m;
  return power(b * b % m, e / 2, m);
}
long long power(long long b, long long e) {
  if (e == 0) return 1;
  if (e & 1) return b * power(b * b, e / 2);
  return power(b * b, e / 2);
}
template <typename T, typename U>
static inline void amin(T &x, U y) {
  if (y < x) x = y;
}
template <typename T, typename U>
static inline void amax(T &x, U y) {
  if (x < y) x = y;
}
template <typename T, typename U>
ostream &operator<<(ostream &os, const pair<T, U> &p) {
  return os << '(' << p.first << "," << p.second << ')';
}
long long inv_n;
bool Q;
void xor_fwht(vector<long long> &a, bool invert) {
  int n = (int)a.size();
  for (int len = 2; len <= n; len <<= 1) {
    for (int i = 0; i < n; i += len) {
      for (int j = 0; j < len / 2; ++j) {
        long long u = a[i + j], v = a[i + j + len / 2];
        a[i + j] = (u + v) % M;
        a[i + j + len / 2] = (u - v + M) % M;
      }
    }
  }
  if (invert) {
    for (int i = 0; i < n; ++i) {
      if (Q)
        a[i] /= n;
      else
        a[i] = (a[i] * inv_n) % M;
    }
  }
}
void xor_fwht2(vector<long long> &a, bool invert) {
  int n = (int)a.size();
  for (int len = 2; len <= n; len <<= 1) {
    for (int i = 0; i < n; i += len) {
      for (int j = 0; j < len / 2; ++j) {
        long long u = a[i + j], v = a[i + j + len / 2];
        a[i + j] = (u + v);
        a[i + j + len / 2] = (u - v);
      }
    }
  }
  if (invert) {
    for (int i = 0; i < n; ++i) {
      a[i] /= n;
    }
  }
}
const int N = 100005;
vector<pair<int, int>> v[N];
bitset<N> vis, cycle;
vector<vector<long long>> ft;
stack<int> st, wt;
void dfs(int s, int p, int w) {
  vis[s] = true;
  st.push(s);
  wt.push(w);
  for (auto j : v[s]) {
    if (!vis[j.first]) {
      dfs(j.first, s, j.second);
    } else if (vis[j.first] && j.first != p && !cycle[j.first]) {
      vector<long long> tmp(1 << 17, 0);
      ++tmp[j.second];
      stack<int> sx, wx;
      cycle[j.first] = true;
      cycle[s] = true;
      while (st.top() != j.first) {
        sx.push(st.top());
        wx.push(wt.top());
        ++tmp[wt.top()];
        st.pop();
        cycle[st.top()] = true;
        wt.pop();
      }
      ft.push_back(tmp);
      while (!sx.empty() && !wx.empty()) {
        st.push(sx.top());
        wt.push(wx.top());
        sx.pop();
        wx.pop();
      }
    }
  }
  assert(!st.empty() && !wt.empty());
  st.pop();
  wt.pop();
}
int _runtimeTerror_() {
  int n, m;
  cin >> n >> m;
  inv_n = power(1 << 17, M - 2, M);
  int answer = 0;
  for (int i = 1; i <= m; ++i) {
    int x, y, w;
    cin >> x >> y >> w;
    v[x].push_back({y, w}), v[y].push_back({x, w});
    answer ^= w;
  }
  dfs(1, 0, 0);
  vector<long long> ans(1 << 17, 0);
  vector<long long> ans2(1 << 17, 0);
  ans2[0] = 1;
  vector<long long> x;
  for (int i = 0; i < (long long)ft.size(); ++i) {
    xor_fwht2(ans2, false);
    xor_fwht2(ft[i], false);
    for (int j = 0; j < (1 << 17); ++j) {
      ans2[j] = ans2[j] * ft[i][j];
    }
    xor_fwht2(ans2, true);
    xor_fwht2(ft[i], true);
    xor_fwht(ft[i], false);
    for (int j = 0; j < (1 << 17); ++j) {
      ans2[j] = ans2[j] > 0;
    }
  }
  for (int i = 0; i < (1 << 17); ++i) {
    ans[i] = 1;
    for (int j = 0; j < (long long)ft.size(); ++j) {
      ans[i] = (ans[i] * ft[j][i]) % M;
    }
  }
  xor_fwht(ans, true);
  long long cnt = 0, Xor = 1700000000000000000;
  for (int i = 0; i < (1 << 17); ++i) {
    if (ans2[i] == 0 && ans[i] != 0) {
      assert(ans[i] == 0);
    }
    if (ans[i] == 0) continue;
    if ((answer ^ i) < Xor) Xor = answer ^ i, cnt = ans[i];
  }
  cout << Xor << " " << cnt << "\n";
  return 0;
}
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  int TESTS = 1;
  while (TESTS--) _runtimeTerror_();
  return 0;
}
