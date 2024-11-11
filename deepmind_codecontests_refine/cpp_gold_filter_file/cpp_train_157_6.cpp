#include <bits/stdc++.h>
using namespace std;
long long mod(long long n) { return n % (long long)1000000007; }
vector<long long> adj[1000005];
long long vis[1000005];
int gcd(int a, int b) {
  if (b == 0) return a;
  return gcd(b, a % b);
}
vector<long long> s;
void dfs(long long n) {
  s.push_back(n);
  vis[n] = 1;
  for (auto i : adj[n]) {
    if (vis[i] == 0) {
      dfs(i);
    }
  }
}
int main() {
  long long n, m;
  cin >> n >> m;
  long long p[n + 1];
  for (long long i = 1; i < n + 1; i = i + 1) {
    cin >> p[i];
  }
  for (long long i = 1; i < m + 1; i = i + 1) {
    long long x, y;
    cin >> x >> y;
    adj[x].push_back(y);
    adj[y].push_back(x);
  }
  long long f[n + 1];
  for (long long i = 1; i < n + 1; i = i + 1) {
    if (vis[i] == 0) {
      vector<long long> ans;
      s.clear();
      dfs(i);
      sort(s.begin(), s.end());
      for (long long i = 0; i < s.size(); i = i + 1) {
        ans.push_back(p[s[i]]);
      }
      sort(ans.begin(), ans.end());
      for (long long i = 0; i < s.size(); i = i + 1) {
        f[s[i]] = ans[s.size() - i - 1];
      }
    }
  }
  for (long long i = 1; i < n + 1; i = i + 1) {
    cout << f[i] << " ";
  }
}
