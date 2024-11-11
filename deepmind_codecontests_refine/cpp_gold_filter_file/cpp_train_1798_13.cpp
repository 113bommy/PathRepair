#include <bits/stdc++.h>
using namespace std;
template <class T>
int chkmax(T& a, T b) {
  if (b > a) {
    a = b;
    return 1;
  }
  return 0;
}
template <class T>
int chkmin(T& a, T b) {
  if (b < a) {
    a = b;
    return 1;
  }
  return 0;
}
template <class iterator>
void output(iterator begin, iterator end, ostream& out = cerr) {
  while (begin != end) {
    out << (*begin) << " ";
    begin++;
  }
  out << endl;
}
template <class T>
void output(T x, ostream& out = cerr) {
  output(x.begin(), x.end(), out);
}
void fast_io() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
}
const int mx = 1e6 + 228;
int n;
vector<vector<int> > g;
long long t[mx], h[mx];
void read() {
  cin >> n;
  for (int i = 0; i < n; ++i) {
    cin >> t[i];
  }
  for (int i = 0; i < n; ++i) {
    cin >> h[i];
  }
  g.resize(n);
  for (int i = 0; i < n - 1; ++i) {
    int u, v;
    cin >> u >> v;
    u--;
    v--;
    g[u].push_back(v);
    g[v].push_back(u);
  }
}
const long long INF = 1e18;
long long dp[mx][2][2];
long long sum_dp, dist0;
int ch_eq, e_to_v, e_from_v;
vector<long long> dist, delta;
void calc_stuff(int v, int pv) {
  e_to_v = 0;
  e_from_v = 0;
  sum_dp = 0;
  ch_eq = 0;
  dist.clear();
  delta.clear();
  dist0 = 0;
  for (auto v1 : g[v]) {
    if (pv != v1) {
      if (h[v1] > h[v]) {
        e_from_v++;
        sum_dp += dp[v1][1][0];
      }
      if (h[v1] < h[v]) {
        e_to_v++;
        sum_dp += dp[v1][0][1];
      }
      if (h[v1] == h[v]) {
        ch_eq++;
        dist0 += dp[v1][0][1];
        delta.push_back(dp[v1][1][0] - dp[v1][0][1]);
      }
    }
  }
  sort(delta.begin(), delta.end());
  dist.push_back(dist0);
  for (int i = 0; i < ch_eq; ++i) {
    dist0 += delta[i];
    dist.push_back(dist0);
  }
}
void calc_dp(int v, int down_e, int up_e) {
  int tot_to_v = e_to_v + down_e;
  int tot_from_v = e_from_v + up_e;
  dp[v][down_e][up_e] = INF;
  for (int i = 0; i <= ch_eq; ++i) {
    chkmin(dp[v][down_e][up_e],
           sum_dp + dist[i] +
               (long long)t[v] *
                   (long long)max(tot_from_v + i, tot_to_v + ch_eq - i));
  }
}
void calc_dp(int v, int pv) {
  for (auto v1 : g[v]) {
    if (v1 != pv) {
      calc_dp(v1, v);
    }
  }
  calc_stuff(v, pv);
  if (v == pv) {
    calc_dp(v, 0, 0);
  } else {
    if (h[pv] <= h[v]) {
      calc_dp(v, 1, 0);
    } else {
      dp[v][1][0] = INF;
    }
    if (h[pv] >= h[v]) {
      calc_dp(v, 0, 1);
    } else {
      dp[v][0][1] = INF;
    }
  }
}
signed main() {
  fast_io();
  read();
  calc_dp(0, 0);
  cout << dp[0][0][0] << '\n';
}
