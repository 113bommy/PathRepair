#include <bits/stdc++.h>
using namespace std;
long long mod = 1000000007;
const long long inf = 92233720368547758;
bool isprime(long long n) {
  for (int i = 2; i * i <= n; i++)
    if (n % i == 0) return 0;
  return 1;
}
long long fpow(long long a, long long b) {
  return b ? fpow(a * a % mod, b / 2) * (b % 2 ? a : 1) % mod : 1;
}
long long gcd(long long a, long long b) { return b ? gcd(b, a % b) : a; }
long long inv(long long i) {
  if (i == 1) return 1;
  return (mod - ((mod / i) * inv(mod % i)) % mod) % mod;
}
long long dtb(long long x) {
  long long ans = 0;
  long long y = 1;
  while (x > 0) {
    ans += (x % 2) * y;
    x = x / 2;
    y = y * 10;
  }
  return ans;
}
vector<long long> adj[100009], vis(100009, 0);
void dfs(long long i) {
  vis[i] = 1;
  for (auto x : adj[i])
    if (!vis[x]) dfs(x);
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  long long T = 1;
  cin >> T;
  long long n, m, k;
  string s, s1, s2;
  string srr[100009];
  long long a, b, c, x = 0, y = 0, z = 0, l, r, t, p, d;
  long long ans = 0, cnt = 0, sum = 0, pos = 0;
  long long mx = 0, mn = 1000000000;
  long long arr[200009];
  vector<long long> va(500009, 0), vb(500009, 0), vc(500009, 0);
  map<long long, long long> make_pair;
  vector<long long> v, v1;
  vector<pair<long long, long long>> v2;
  while (T--) {
    cin >> s >> m;
    char o[m], last;
    vector<char> str;
    n = s.size();
    for (int i = 0; i < m; i++) cin >> arr[i];
    for (int i = 0; i < n; i++) str.push_back(s[i]);
    sort((str).begin(), (str).end());
    reverse((str).begin(), (str).end());
    long long j = 0;
    cnt = 0;
    while (true) {
      bool ok = 0;
      while (str[j] == last) j++;
      while (count(arr, arr + m, 0) > count((str).begin(), (str).end(), str[j]))
        j++;
      for (int i = 0; i < m; i++) {
        if (arr[i] == 0) {
          o[i] = str[j];
          last = str[j];
          j++;
          v.push_back(i);
          arr[i] = -1;
          ok = 1;
          cnt++;
        }
      }
      for (auto x : v) {
        for (int i = 0; i < m; i++) {
          if (arr[i] > 0) arr[i] = arr[i] - abs(i - x);
        }
      }
      if (!ok) break;
      v.clear();
      if (cnt == m) break;
    }
    for (auto x : o) cout << x;
    cout << "\n";
  }
  return 0;
}
