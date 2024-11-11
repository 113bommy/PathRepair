#include <bits/stdc++.h>
using namespace std;
long long int M = 1e9 + 7;
long long int inf = 9 * 1e18;
int findMinNumber(int n) {
  int count = 0, ans = 1;
  while (n % 2 == 0) {
    count++;
    n /= 2;
  }
  if (count % 2) ans *= 2;
  for (int i = 3; i <= sqrt(n); i += 2) {
    count = 0;
    while (n % i == 0) {
      count++;
      n /= i;
    }
    if (count % 2) ans *= i;
  }
  if (n > 2) ans *= n;
  return ans;
}
long long binpow(long long val, long long deg) {
  if (deg < 0) return 0;
  if (!deg) return 1 % M;
  if (deg & 1) return binpow(val, deg - 1) * val % M;
  long long res = binpow(val, deg >> 1);
  return (res * res) % M;
}
long long modinv(long long n) { return binpow(n, M - 2); }
bool sortbysec(const pair<int, int> &a, const pair<int, int> &b) {
  return (a.second > b.second);
}
vector<int> ar[100001];
int vis[100001];
int c;
void dfs(int node) {
  vis[node] = 1;
  c++;
  for (int child : ar[node]) {
    if (!vis[child]) {
      dfs(child);
    }
  }
}
void solve() {
  int n, m;
  cin >> n >> m;
  vector<string> v_s(n);
  for (long long i = 0; i < n; i++) {
    cin >> v_s[i];
  }
  int ans = 1;
  for (long long i = 0; i < m; i++) {
    set<char> s1;
    for (long long j = 0; j < n; j++) {
      s1.insert(v_s[j][i]);
    }
    ans = (ans * (int)s1.size()) % M;
  }
  cout << ans << "\n";
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  int t;
  t = 1;
  while (t--) {
    solve();
  }
  return 0;
}
