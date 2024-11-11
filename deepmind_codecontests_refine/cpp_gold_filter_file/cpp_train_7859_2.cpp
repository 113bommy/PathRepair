#include <bits/stdc++.h>
using namespace std;
template <typename _T>
inline void _DBG(const char *s, _T x) {
  cerr << s << " = " << x << "\n";
}
template <typename _T, typename... args>
void _DBG(const char *s, _T x, args... a) {
  while (*s != ',') cerr << *s++;
  cerr << " = " << x << ',';
  _DBG(s + 1, a...);
}
const int N = 15e3 + 7;
const long long P = 1e7 + 19;
const int Q = 1e9 + 7;
int n, k, in[N], out[N], w[N], v[N];
void update(vector<int> &vec, int id) {
  for (int i = k; i >= w[id]; i--) {
    vec[i] = max(vec[i], vec[i - w[id]] + v[id]);
  }
}
void solve(int l, int r, vector<int> vec, vector<int> &can) {
  if (l == r) {
    for (auto u : can) {
      if (in[u] <= l && r <= out[u]) {
        update(vec, u);
      }
    }
    long long ans = 0;
    for (int m = k; m; m--) {
      ans = (P * ans + vec[m]) % Q;
    }
    cout << ans << "\n";
    return;
  }
  int m = (l + r) / 2;
  vector<int> can2;
  for (auto u : can) {
    if (in[u] <= l && r <= out[u]) {
      update(vec, u);
    } else {
      can2.push_back(u);
    }
  }
  solve(l, m, vec, can2);
  solve(m + 1, r, vec, can2);
}
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  cin >> n >> k;
  int last = 0;
  for (int i = 1; i <= n; i++) {
    cin >> v[i] >> w[i];
    in[i] = last + 1;
    out[i] = 3 * N;
  }
  int q;
  cin >> q;
  while (q--) {
    int t;
    cin >> t;
    if (t == 3) {
      last++;
    }
    if (t == 2) {
      int x;
      cin >> x;
      out[x] = last;
    }
    if (t == 1) {
      n++;
      cin >> v[n] >> w[n];
      in[n] = last + 1;
      out[n] = 3 * N;
    }
  }
  vector<int> emp(k + 1, 0), can;
  for (int i = 1; i <= n; i++) {
    can.push_back(i);
  }
  solve(1, last, emp, can);
  return 0;
}
