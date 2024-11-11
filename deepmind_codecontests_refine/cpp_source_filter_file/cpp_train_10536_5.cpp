#include <bits/stdc++.h>
using namespace std;
void c_p_c() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
}
long long me(long long x, long long y, long long p) {
  long long res = 1;
  x = x % p;
  if (x == 0) return 0;
  while (y > 0) {
    if (y & 1) res = (res * x) % p;
    y = y >> 1;
    x = (x * x) % p;
  }
  return res;
}
bool check2(vector<long long int> v, long long int l, long long int sum) {
  bool knap[v.size() + 1][sum + 1];
  for (int i = 0; i <= v.size(); i++) knap[i][0] = true;
  for (int i = 1; i <= sum; i++) knap[0][i] = false;
  for (long long int i = 1; i < v.size() + 1; i++) {
    for (long long int j = 1; j < sum + 1; j++) {
      if (v[i - 1] <= j)
        knap[i][j] = knap[i - 1][j] || knap[i - 1][j - v[i - 1]];
      else
        knap[i][j] = knap[i - 1][j];
    }
  }
  if (knap[v.size()][sum])
    return true;
  else
    return false;
}
bool check33(string s1) {
  long long int n = s1.size();
  set<char> s;
  for (long long int i = 0; i < n; i++) s.insert(s1[i]);
  if (s.size() == 1) return true;
  return false;
}
string kmp_algo(string s) {
  long long int n = s.length();
  long long int pi[n];
  pi[0] = 0;
  for (long long int i = 1; i < n; i++) {
    long long int l = pi[i - 1];
    while (l > 0 && s[l] != s[i]) {
      l = pi[l - 1];
    }
    if (s[i] == s[l]) l++;
    pi[i] = l;
  }
  string temp = s.substr(0, pi[n - 1]);
  return temp;
}
long long int poww(long long int x, long long int y, long long int p) {
  long long int res = 1;
  x = x % p;
  while (y > 0) {
    if (y & 1) res = (res * x) % p;
    y = y >> 1;
    x = (x * x) % p;
  }
  return res;
}
long long int modInverse(long long int n, long long int p) {
  return poww(n, p - 2, p);
}
long long int nCr(long long int n, long long int r, long long int p) {
  if (r == 0) return 1;
  if (r > n) return 0;
  long long int fac[n + 1];
  fac[0] = 1;
  for (int i = 1; i <= n; i++) fac[i] = (fac[i - 1] * i) % p;
  return (fac[n] * modInverse(fac[r], p) % p * modInverse(fac[n - r], p) % p) %
         p;
}
void dfs(vector<vector<long long>> &adj, vector<long long> &v, long long val,
         vector<long long> &visited) {
  if (visited[val] == 1) return;
  visited[val] = 1;
  v.push_back(val);
  for (auto x : adj[val]) {
    dfs(adj, v, x, visited);
  }
}
bool func(long long int a[], long long int n) {
  set<long long int> s;
  for (long long int i = 0; i < n; i++) s.insert(a[i]);
  if (s.size() == 1) return true;
  return false;
}
void solve() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  long long int n;
  string s;
  cin >> s;
  n = s.size();
  if (n == 1) {
    cout << 0 << endl << endl;
    return;
  }
  map<char, long long int> m;
  for (long long int i = 0; i < n; i++) m[s[i]]++;
  long long int l = m['L'], r = m['R'], u = m['U'], d = m['D'];
  if (l > 0 && r > 0 && d > 0 && u > 0) {
    cout << 2 * min(l, r) + 2 * min(u, d) << endl;
    for (long long int i = 0; i < min(l, r); i++) cout << 'L';
    for (long long int i = 0; i < min(u, d); i++) cout << 'U';
    for (long long int i = 0; i < min(l, r); i++) cout << 'R';
    for (long long int i = 0; i < min(u, d); i++) cout << 'D';
    cout << endl;
    return;
  }
  if (l == 0 || r == 0) {
    if (u > 0 && d > 0)
      cout << 2 << endl << "UD" << endl;
    else
      cout << 0 << endl << endl;
    return;
  }
  if (d == 0 || u == 0) {
    if (l > 0 && r > 0)
      cout << 2 << endl << "UD" << endl;
    else
      cout << 0 << endl << endl;
    return;
  }
}
int main() {
  c_p_c();
  long long int t;
  cin >> t;
  while (t--) {
    solve();
  }
  return 0;
}
