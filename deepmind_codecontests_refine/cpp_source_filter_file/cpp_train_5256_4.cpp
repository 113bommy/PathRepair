#include <bits/stdc++.h>
using namespace std;
const int N = 200 * 1001, M = 26, P = 163, MOD = 1e6 + 3, SEED1 = 577,
          SEED2 = 811;
int n, m, hsh[M][N], hsh2[M][N], to[M], inv[N], hsh_substr[M], hsh_substr2[M],
    pw[N], ex[M][N];
bool mark[N], ex2[M];
vector<int> res, num;
vector<int> where[MOD];
unordered_set<int> hsh_vec;
string s, t;
int _sum(int a, int b) {
  a += b;
  if (MOD < a) a -= MOD;
  return a;
}
int _sub(int a, int b) {
  a -= b;
  if (a < 0) a += MOD;
  return a;
}
int _mul(int a, int b) { return 1LL * a * b % MOD; }
int power(int a, int b) {
  if (!b) return 1;
  int t = power(a, b / 2);
  if (b % 2) return _mul(_mul(t, t), a);
  return _mul(t, t);
}
bool sz(int h) {
  int cnt = 0;
  for (auto x : where[h]) {
    if (!mark[x]) {
      cnt++;
      num.push_back(x);
    }
    mark[x] = true;
  }
  for (auto x : where[h]) mark[x] = false;
  if (cnt == 1) {
    if (where[h].size() == 1) return false;
    num.push_back(num[0]);
  }
  return cnt <= 2;
}
void del() {
  for (auto h : hsh_vec) where[h].clear();
  hsh_vec.clear();
}
bool solve(int st) {
  int en = st + m - 1;
  for (int i = 0; i < M; i++) {
    hsh_substr[i] = _sub(hsh[i][en], (!st ? 0 : hsh[i][st - 1]));
    hsh_substr[i] = _mul(inv[st], hsh_substr[i]);
    hsh_substr2[i] = hsh2[i][m - 1];
    if (ex[i][en] - (!st ? 0 : ex[i][st - 1])) {
      where[hsh_substr[i]].push_back(i);
      hsh_vec.insert(hsh_substr[i]);
    }
    if (ex2[i]) {
      where[hsh_substr2[i]].push_back(i);
      hsh_vec.insert(hsh_substr2[i]);
    }
    to[i] = -1;
  }
  for (auto h : hsh_vec) {
    num.clear();
    if (!sz(h)) {
      del();
      return false;
    }
    if (to[num[0]] != -1 && to[num[0]] != num[1]) {
      del();
      return false;
    }
    if (to[num[1]] != -1 && to[num[1]] != num[0]) {
      del();
      return false;
    }
    to[num[0]] = num[1];
    to[num[1]] = num[0];
  }
  for (auto h : hsh_vec) where[h].clear();
  hsh_vec.clear();
  return true;
}
int main() {
  ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);
  cin >> n >> m;
  cin >> s >> t;
  for (int i = 0; i < m; i++) ex2[t[i] - 'a'] = true;
  ex[s[0] - 'a'][0] = 1;
  for (int i = 1; i < n; i++) {
    for (int j = 0; j < M; j++) {
      ex[j][i] = ex[j][i - 1];
      ex[j][i] += (s[i] - 'a' == j);
    }
  }
  hsh[s[0] - 'a'][0] = SEED1;
  for (int i = 0; i < M; i++)
    if (s[0] - 'a' != i) hsh[i][0] = SEED2;
  pw[0] = 1;
  for (int i = 1; i < n; i++) {
    pw[i] = _mul(pw[i - 1], P);
    for (int j = 0; j < M; j++) {
      if (s[i] - 'a' == j)
        hsh[j][i] = _sum(hsh[j][i - 1], _mul(pw[i], SEED1));
      else
        hsh[j][i] = _sum(hsh[j][i - 1], _mul(pw[i], SEED2));
    }
  }
  hsh2[t[0] - 'a'][0] = SEED1;
  for (int i = 0; i < M; i++)
    if (t[0] - 'a' != i) hsh2[i][0] = SEED2;
  for (int i = 1; i < m; i++) {
    for (int j = 0; j < M; j++) {
      if (t[i] - 'a' == j)
        hsh2[j][i] = _sum(hsh2[j][i - 1], _mul(pw[i], SEED1));
      else
        hsh2[j][i] = _sum(hsh2[j][i - 1], _mul(pw[i], SEED2));
    }
  }
  inv[n - 1] = power(pw[n - 1], MOD - 2);
  for (int i = n - 2; 0 <= i; i--) inv[i] = _mul(inv[i + 1], P);
  for (int i = 0; i <= n - m; i++) {
    if (solve(i)) res.push_back(i + 1);
  }
  cout << res.size() << "\n";
  for (auto x : res) cout << x << " ";
}
