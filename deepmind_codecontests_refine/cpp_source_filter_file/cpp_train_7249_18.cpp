#include <bits/stdc++.h>
using namespace std;
inline void Input_Output() {}
const double eps = 0.000001;
const long double pi = acos(-1);
const int maxn = 1e7 + 9;
const int mod = 1e9 + 7;
const long long MOD = 1e18 + 9;
const long long INF = 1e16 + 123;
const int inf = 2e9 + 11;
const int mxn = 1e6 + 9;
const int N = 6e5 + 123;
const int K = 80;
const int pri = 997;
const int Magic = 2101;
const int dx[] = {-1, 0, 1, 0};
const int dy[] = {0, -1, 0, 1};
int n, m, k, x;
vector<int> state;
int ids[(1 << 8)];
struct Mat {
  long long d[K][K];
  Mat(long long val = INF) {
    for (int i = 0; i < K; ++i)
      for (int j = 0; j < K; ++j) d[i][j] = INF;
  }
  Mat operator+(Mat &b) {
    Mat res;
    for (int i = 0; i < K; ++i)
      for (int j = 0; j < K; ++j)
        for (int k = 0; k < K; ++k)
          res.d[i][j] = min(res.d[i][j], d[i][k] + b.d[k][j]);
    return res;
  }
  void print() {
    for (int i = 0; i < K; ++i) {
      for (int j = 0; j < K; ++j) {
        if (d[i][j] == INF) {
          cout << "bd ";
          continue;
        }
        cout << d[i][j] << ' ';
      }
      cout << '\n';
    }
  }
};
Mat make_matrix(vector<long long> &c) {
  assert((int)(c.size()) == k);
  Mat res;
  for (int id = 0; id < (int)(state.size()); ++id) {
    int msk = state[id];
    if (msk % 2 == 0) {
      int nmsk = msk / 2;
      res.d[id][ids[nmsk]] = 0;
      continue;
    }
    for (int i = 0; i < k; ++i) {
      int nmsk = (msk >> 1);
      if (nmsk & (1 << i)) {
        continue;
      }
      nmsk |= (1 << i);
      res.d[id][ids[nmsk]] = min(res.d[id][ids[nmsk]], c[i]);
    }
  }
  return res;
}
int main() {
  ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
  cin >> x >> k >> n >> m;
  for (int msk = 0; msk < (1 << k); ++msk) {
    ids[msk] = -1;
    if (__builtin_popcount(msk) != x) {
      continue;
    }
    ids[msk] = (int)(state.size());
    state.push_back(msk);
  }
  vector<long long> c(k);
  for (auto &e : c) cin >> e;
  vector<int> pos = {0, n - x};
  vector<pair<int, int> > spec(m);
  for (auto &it : spec) {
    cin >> it.first >> it.second;
    it.first--;
    for (int i = 0; i <= k; ++i) {
      int s = it.first - i;
      s = max(s, 0);
      s = min(s, n - x);
      pos.push_back(s);
    }
  }
  sort(pos.begin(), pos.end());
  pos.resize(unique(pos.begin(), pos.end()) - pos.begin());
  vector<Mat> Pw;
  Pw.push_back(make_matrix(c));
  int bit = 0;
  while ((1 << bit) <= n) {
    ++bit;
    Pw.push_back(Pw.back() + Pw.back());
  }
  Mat cur;
  for (int i = 0; i < K; ++i) cur.d[i][i] = 0;
  for (int it = 0; it + 1 < (int)(pos.size()); ++it) {
    int l = pos[it], r = pos[it + 1];
    vector<long long> nc = c;
    for (auto s : spec) {
      if (s.first > l && s.first <= l + k) {
        nc[s.first - l - 1] += s.second;
      }
    }
    if (nc != c) {
      Mat cn = make_matrix(nc);
      cur = cur + cn;
    } else {
      int dif = r - l;
      for (int i = 0; i < (int)(Pw.size()); ++i) {
        if (dif & (1 << i)) {
          cur = cur + Pw[i];
        }
      }
    }
  }
  int fin = (1 << x) - 1;
  fin = ids[fin];
  assert(fin != -1);
  cout << cur.d[fin][fin] << '\n';
  return 0;
}
