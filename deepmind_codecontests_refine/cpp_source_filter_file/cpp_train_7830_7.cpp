#include <bits/stdc++.h>
using namespace std;
const long double pi = acos(-1.0);
long long powm(long long a, long long b, long long m) {
  if (b == 0) return 1;
  long long t = powm(a, b / 2, m);
  if (b % 2) return a * t % m * t % m;
  return t * t % m;
}
long long modinv1(long long b, long long m) { return powm(b, m - 2, m); }
bool comp(const pair<long long, long long> &p1,
          const pair<long long, long long> &p2) {
  if (abs(p1.first) == abs(p2.first)) return (abs(p1.second) < abs(p2.second));
  return (abs(p1.first) < abs(p2.first));
}
long long modinv(long long n, long long m) {
  long long i = 0;
  for (i = 1; i < m; ++i)
    if ((n * i) % m == 1) return i;
}
vector<char> adj[26];
bool vis[26];
vector<char> df;
bool checkcycle(char v, char parent) {
  vis[v - 'a'] = 1;
  long long i;
  for (i = 0; i < adj[v - 'a'].size(); ++i) {
    if (!vis[adj[v - 'a'][i] - 'a']) {
      if (checkcycle(adj[v - 'a'][i], v)) return true;
    } else if (adj[v - 'a'][i] != parent)
      return true;
  }
  return false;
}
bool vis1[26];
void dfs(char c) {
  vis1[c - 'a'] = 1;
  df.push_back(c);
  long long i;
  for (i = 0; i < adj[c - 'a'].size(); ++i) {
    if (!vis1[adj[c - 'a'][i] - 'a']) dfs(adj[c - 'a'][i]);
  }
}
long long ncr(long long n, long long r, long long m) {
  long long ans = 1;
  long long k = 0;
  while (k < r) {
    ans = (ans * (n - k) % 998244353) * modinv1(k + 1, 998244353) % 998244353;
    k++;
  }
  return ans;
}
long long a[40005], b[40005];
void DJ() {
  long long n;
  cin >> n;
  string s;
  cin >> s;
  long long ct = 0, ans = 0;
  long long i = 0;
  while (i < n) {
    if (s[i] == '(')
      ct++;
    else
      ct--;
    if (ct < 0) ans++;
    if (ct == 0 && s[i - 1] == '(') ans++;
    i++;
  }
  if (ct)
    cout << -1;
  else
    cout << ans;
}
signed main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  long long t = 1, i;
  while (t--) DJ();
  return 0;
}
