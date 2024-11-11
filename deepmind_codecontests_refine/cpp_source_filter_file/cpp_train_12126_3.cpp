#include <bits/stdc++.h>
#pragma GCC optimize("Ofast")
using namespace std;
long long int invmod(long long int x, long long int n, long long int mod) {
  if (n == 0) return 1 % mod;
  long long int half = invmod(x, n / 2, mod);
  half = (half * half) % mod;
  if (n % 2 == 1) half = (half * (x % mod)) % mod;
  return half;
}
long long int bin(long long int a[], long long int l, long long int r,
                  long long int x) {
  if (l <= r) {
    long long int m = l + (r - l) / 2;
    if (a[m] == x)
      return m;
    else if (a[m] > x)
      return bin(a, l, m - 1, x);
    else
      return bin(a, m + 1, r, x);
  } else
    return -1;
}
long long int power(long long int b, long long int e, long long int m) {
  if (e == 0) return 1;
  if (e % 2)
    return b * power(b * b % m, (e - 1) / 2, m) % m;
  else
    return power(b * b % m, e / 2, m);
}
long long int power(long long int b, long long int e) {
  if (e == 0) return 1;
  if (e % 2)
    return b * power(b * b, (e - 1) / 2);
  else
    return power(b * b, e / 2);
}
long long int ncr(long long int n, long long int r, long long int x) {
  if (r == 0) return 1;
  long long int fac[n + 1];
  fac[0] = 1;
  for (long long int i = 1; i <= n; i++) fac[i] = fac[i - 1] * i % x;
  return (fac[n] * power(fac[r], x - 2, x) % x * power(fac[n - r], x - 2, x) %
          x) %
         x;
}
long long int ncr(long long int n, long long int p) {
  long long int r = min(p, n - p), rf = 1, ln = 1;
  for (long long int i = 1; i <= r; i++) rf = rf * i;
  for (long long int i = 0; i < r; i++) ln = ln * (n - i);
  return ln / rf;
}
bool sbs(pair<long long int, long long int> &a,
         pair<long long int, long long int> &b) {
  return (a.second < b.second);
}
bool sbds(pair<long long int, long long int> &a,
          pair<long long int, long long int> &b) {
  return (a.second > b.second);
}
bool sdf(pair<long long int, long long int> &a,
         pair<long long int, long long int> &b) {
  return (a.first > b.first);
}
long long int SUM(long long int a[], long long int n) {
  long long int sum = 0;
  for (long long int i = 0; i < n; i++) sum += a[i];
  return sum;
}
long long int chkprm(long long int n) {
  long long int x = 5, s = sqrt(n);
  if (n < 2) return 0;
  if (n < 4) return 1;
  if ((n & 1) == 0) return 0;
  if (n % 3 == 0) return 0;
  while (x <= s) {
    if (n % x == 0) return 0;
    x += 2;
    if (n % x == 0) return 0;
    x += 4;
  }
  return 1;
}
vector<long long int> adj1[26], adj2[26], comp, ord, vis(26);
void dfs1(long long int x) {
  vis[x] = 1;
  for (auto i : adj1[x])
    if (!vis[i]) dfs1(i);
  ord.push_back(x);
}
void dfs2(long long int x) {
  vis[x] = 1;
  comp.push_back(x);
  for (auto i : adj2[x])
    if (!vis[i]) dfs2(i);
}
void myth() {
  long long int n;
  cin >> n;
  string s[n];
  if (n == 1) {
    cout << "asdfghjklqwertyuiopzxcvbnm";
    return;
  }
  for (long long int i = 0; i < n; i++) cin >> s[i];
  for (long long int i = 0; i < n - 2; i++) {
    long long int chk = 0;
    for (long long int j = 0; j < min(s[i].length(), s[i + 1].length()); j++)
      if (s[i][j] != s[i + 1][j]) {
        chk++;
        adj1[s[i][j] - 'a'].push_back(s[i + 1][j] - 'a');
        adj2[s[i + 1][j] - 'a'].push_back(s[i][j] - 'a');
        break;
      }
    if (chk == 0 && s[i].length() > s[i + 1].length()) {
      cout << "impossible";
      return;
    }
  }
  for (char c = 'a'; c <= 'z'; c++)
    if (adj1[c - 'a'].empty()) {
      adj1[c - 'a'].push_back(c - 'a');
      adj2[c - 'a'].push_back(c - 'a');
    }
  for (long long int i = 0; i < 26; i++)
    if (!vis[i]) dfs1(i);
  for (long long int i = 0; i < 26; i++) vis[i] = 0;
  for (long long int i = 0; i < 26; i++) {
    if (!vis[ord[25 - i]]) {
      dfs2(ord[25 - i]);
      if (comp.size() > 1) {
        cout << "impossible";
        return;
      }
      comp.clear();
    }
  }
  reverse(ord.begin(), ord.end());
  for (auto i : ord) cout << char('a' + i);
}
signed main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  long long int test_case = 1;
  while (test_case--) {
    myth();
    cout << "\n";
  }
  cerr << "\n"
       << "Time Elasped : " << 1.0 * clock() / CLOCKS_PER_SEC << "\n";
  return 0;
}
