#include <bits/stdc++.h>
long long p = 1000000007;
using namespace std;
long long sq(long long i) { return i * i; }
long long fact(long n) {
  long ans = 1;
  for (long i = 1; i <= n; i++) ans = (ans * i) % p;
  return ans;
}
long long power(long x, long n) {
  if (n == 0) return 1;
  if (n == 1) return x;
  long ans = power(x, n / 2);
  if (n % 2 == 0)
    return ans * ans;
  else
    return ans * ans * x;
}
void dfs(vector<long> v[], vector<long> &df, long cov[], long i) {
  df.push_back(i);
  for (long j = 0; j < v[i].size(); j++) {
    if (cov[v[i][j]] == 0) {
      cov[v[i][j]] = cov[i];
      dfs(v, df, cov, v[i][j]);
    }
  }
}
void djikstra(vector<pair<long, long>> v[], long d[], long par[], long s,
              long n) {
  for (long i = 0; i < n; i++) {
    d[i] = 1000000001;
    par[i] = -1;
  }
  par[s] = s;
  d[s] = 0;
  bool cov[n];
  for (long i = 0; i < n; i++) cov[i] = 0;
  long u = -1;
  for (int j = 0; j < n; j++) {
    u = -1;
    for (long i = 0; i < n; i++) {
      if (!cov[i] && (d[i] < d[u] || u == -1)) u = i;
    }
    cov[u] = 1;
    for (long i = 0; i < v[u].size(); i++) {
      if (d[v[u][i].first] > d[u] + v[u][i].second) {
        d[v[u][i].first] = d[u] + v[u][i].second;
        par[v[u][i].first] = u;
      }
    }
  }
}
long findConnComp(vector<long> v[], long cov[], long n) {
  long j = 0;
  vector<long> df;
  for (long i = 0; i < n; i++) cov[i] = 0;
  for (long i = 0; i < n; i++) {
    if (!cov[i]) {
      cov[i] = ++j;
      dfs(v, df, cov, i);
    }
  }
  return j;
}
int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  long t;
  cin >> t;
  while (t--) {
    int n, kk, k;
    cin >> n >> kk;
    string s;
    cin >> s;
    pair<int, int> a[26];
    for (int i = 0; i < 26; i++) {
      a[i].first = 0;
      a[i].second = 1;
    }
    for (int i = 0; i < s.length(); i++) a[s[i] - 'a'].first++;
    int maxx = 0;
    sort(a, a + 26);
    for (int r = 1; r <= kk; r++) {
      if (kk % r == 0) {
        k = r;
        int minn = n * 2;
        for (int i = 0; i < 26; i++) a[i].second = 1;
        for (int i = 0; i < k; i++) {
          int x = 0;
          for (int i = 1; i < 26; i++)
            if (a[i].first / a[i].second > a[x].first / a[x].second) x = i;
          minn = a[x].first / a[x].second;
          a[x].second++;
        }
        if (maxx < minn * k) {
          maxx = minn * k;
        }
      }
    }
    cout << maxx << "\n";
  }
}
