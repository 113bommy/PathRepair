#include <bits/stdc++.h>
using namespace std;
long long z = 1e9 + 7;
long long gcd(long long a, long long b) {
  if (a == 0) return b;
  if (b == 0) return a;
  return gcd(b, a % b);
}
long long power(long long a, long long b) {
  long long res = 1;
  while (b) {
    if (b & 1) {
      res = (res * a) % z;
      b--;
    } else {
      a = (a * a) % z;
      b = b >> 1;
    }
  }
  return res;
}
vector<long long> sieve;
vector<long long> v[2005];
long long vis[2001], ans = 0;
void dfs(long long u) {
  vis[u] = 1;
  ans++;
  if (v[u].size() && !vis[v[u][0]]) dfs(v[u][0]);
}
int32_t main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  sieve.assign(1000001, 0);
  for (long long i = 2; i < 1000; i++) {
    if (!sieve[i]) {
      for (long long j = i * i; j <= 1000000; j += i) {
        sieve[j] = 1;
      }
    }
  }
  long long t;
  t = 1;
  cin >> t;
  while (t--) {
    long long n, k;
    cin >> n >> k;
    string s;
    long long ar[26] = {0};
    cin >> s;
    for (long long i = 0; i < n; i++) ar[s[i] - 'a']++;
    long long ans1 = 1;
    for (long long i = n; i >= 1; i--) {
      for (long long j = 0; j <= 2000; j++) v[j].clear();
      for (long long j = 1; j <= i; j++) {
        if ((j + k) % i)
          v[j].push_back((j + k) % i);
        else
          v[j].push_back(i);
      }
      memset(vis, 0, sizeof(vis));
      vector<long long> v2;
      for (long long j = 1; j <= i; j++) {
        if (!vis[j]) {
          ans = 0;
          dfs(j);
          v2.push_back(ans);
        }
      }
      sort(v2.begin(), v2.end());
      long long ar1[26] = {0};
      for (long long j = 0; j < 26; j++) ar1[j] = ar[j];
      long long pos = 1;
      for (long long j = v2.size() - 1; j >= 0; j--) {
        long long p = 0;
        for (long long k = 0; k < 26; k++) {
          if (ar1[k] >= v2[j]) {
            ar1[k] -= v2[j];
            p = 1;
            break;
          }
        }
        if (!p) {
          pos = 0;
          break;
        }
      }
      if (pos) {
        ans1 = i;
        break;
      }
    }
    cout << ans1 << "\n";
  }
}
