#include <bits/stdc++.h>
using namespace std;
const long long mod = 998244353;
long long sum(long long a, long long b) {
  a += b;
  if (a >= mod) a -= mod;
  if (a < 0) a += mod;
  return a;
}
long long p[1 << 5];
map<int, vector<pair<int, int>>> mp;
void solve(vector<pair<int, int>> &v, int t) {
  vector<int> x;
  for (int i = 0; i < v.size(); i++)
    if (v[i].second == 0) x.push_back(i);
  int k = x.size();
  if (k == 0) {
    long long s = 0;
    for (auto &i : v) s = sum(s, i.first * p[i.second] % mod);
    mp[s] = v;
    return;
  }
  if (k == 1) {
    v[x[0]].second = t;
    solve(v, t);
    v[x[0]].second = 0;
    return;
  }
  k /= 2;
  for (int i = 0; i < (1 << k); i++) {
    for (int j = 0; j < k; j++) {
      int y = x[2 * j + (i >> j & 1)];
      v[y].second = x.size() + 1;
    }
    solve(v, t);
    for (int j = 0; j < k; j++) {
      int y = x[2 * j + (i >> j & 1)];
      v[y].second = 0;
    }
  }
}
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  int k, a, h;
  cin >> k >> a >> h;
  p[0] = 1;
  for (int i = 1; i <= (1 << k); i++) p[i] = p[i - 1] * a % mod;
  vector<pair<int, int>> f, s;
  for (int i = 1; i <= (1 << (k - 1)); i++) f.push_back({i, 0});
  for (int i = (1 << (k - 1)) + 1; i <= (1 << k); i++) s.push_back({i, 0});
  map<int, vector<pair<int, int>>> a1, a2, b1, b2;
  solve(f, 1);
  a1 = mp;
  mp.clear();
  solve(s, 1);
  b1 = mp;
  mp.clear();
  solve(f, 2);
  a2 = mp;
  mp.clear();
  solve(s, 2);
  b2 = mp;
  mp.clear();
  for (auto &i : a1) {
    if (b2.count(sum(h, -i.first))) {
      vector<pair<int, int>> ans = i.second;
      for (auto &j : b2[sum(h, -i.first)]) ans.push_back(j);
      for (auto &j : ans) cout << j.second << " \n"[&j == &ans.back()];
      exit(0);
    }
  }
  for (auto &i : a2) {
    if (b1.count(sum(h, -i.first))) {
      vector<pair<int, int>> ans = i.second;
      for (auto &j : b1[sum(h, -i.first)]) ans.push_back(j);
      for (auto &j : ans) cout << j.second << " \n"[&j == &ans.back()];
      exit(0);
    }
  }
  cout << "-1\n";
  return 0;
}
