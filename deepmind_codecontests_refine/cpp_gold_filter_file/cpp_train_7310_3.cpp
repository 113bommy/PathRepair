#include <bits/stdc++.h>
using namespace std;
const int mod = 998244353;
int MAX = 2020;
vector<int> f(vector<int> v) {
  long long s = 0;
  for (int x : v) s += x;
  if (s > MAX) return vector<int>(MAX + 1, 1);
  sort(v.rbegin(), v.rend());
  int it = 1;
  vector<int> res;
  for (int c : v) {
    for (int i = 0; i < c; ++i) {
      res.push_back(it);
    }
    ++it;
  }
  return res;
}
vector<int> f(vector<int> v, int k) {
  for (int i = 0; i < k; ++i) {
    if (v.size() > MAX) return v;
    v = f(v);
  }
  return v;
}
int eval(vector<int> v, int k) { return f(v, k).size(); }
vector<int> cur;
vector<vector<int> > tot;
void rec(int mi, int k) {
  if (mi <= 30) rec(mi + 1, k);
  cur.push_back(mi);
  if (eval(cur, k) <= MAX) {
    tot.push_back(cur);
    rec(mi, k);
  }
  cur.pop_back();
}
int main() {
  std::ios::sync_with_stdio(false);
  std::cin.tie(0);
  int n, k;
  cin >> n >> k;
  if (k >= 4) {
    MAX = n;
    rec(1, k);
    cout << tot.size() << endl;
  } else if (k == 1) {
    vector<int> d(n + 1);
    d[0] = 1;
    for (int i = 1; i <= n; ++i) {
      for (int j = 0; j <= n - i; ++j) {
        d[j + i] = (d[j + i] + d[j]) % mod;
      }
    }
    long long res = 0;
    for (int i = 1; i <= n; ++i) res = (res + d[i]) % mod;
    cout << res << endl;
  } else if (k == 2) {
    vector<vector<int> > d(80, vector<int>(n + 1));
    d[0][0] = 1;
    for (int i = n; i > 0; --i) {
      for (int c = 0; c + 1 < d.size(); ++c)
        for (int j = 0; j + (c + 1) * i < d[c].size(); ++j)
          if (d[c][j]) {
            d[c + 1][j + (c + 1) * i] =
                (d[c + 1][j + (c + 1) * i] + d[c][j]) % mod;
          }
    }
    long long res = 0;
    for (int c = 1; c < d.size(); ++c)
      for (int i = 1; i <= n; ++i) res = (res + d[c][i]) % mod;
    cout << res << endl;
  } else {
    vector<vector<vector<int> > > d(
        30, vector<vector<int> >(500, vector<int>(n + 1)));
    d[0][0][0] = 1;
    for (int i = min(n, 80); i > 0; --i) {
      for (int c = 0; c + 1 < d.size(); ++c)
        for (int s = 0; s + i * (c + 1) < d[c].size(); ++s)
          for (int j = 0; j <= n; ++j)
            if (d[c][s][j]) {
              int s1 = s + i * (c + 1);
              int j1 = j + (c + 1) * (i + 1) * i / 2 + i * s;
              if (j1 > n) break;
              d[c + 1][s1][j1] = (d[c + 1][s1][j1] + d[c][s][j]) % mod;
            }
    }
    long long res = 0;
    for (int c = 1; c < d.size(); ++c)
      for (int s = 0; s < d[c].size(); ++s)
        for (int i = 1; i <= n; ++i) {
          res = (res + d[c][s][i]) % mod;
        }
    cout << res << endl;
  }
  return 0;
}
