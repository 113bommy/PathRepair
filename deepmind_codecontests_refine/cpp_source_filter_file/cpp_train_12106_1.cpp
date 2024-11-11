#include <bits/stdc++.h>
using namespace std;
long long binpow(long long a, long long n, long long mod) {
  long long ans = 1;
  while (n) {
    if (n & 1) ans = (ans * a) % mod;
    a = (a * a) % mod;
    n >>= 1;
  }
  return ans;
}
long long binpow(long long a, long long n) {
  long long ans = 1;
  while (n) {
    a *= a;
    n >>= 1;
  }
  return ans;
}
vector<long long> pr;
void PrDoX(long long x) {
  if (pr.size() > 0) return;
  vector<long long> p(x + 1);
  for (long long i = 2; i <= x; i++) {
    if (p[i] == 0) {
      pr.push_back(i);
      for (long long j = i + i; j <= x; j += i) p[j] = 1;
    }
  }
}
vector<long long> fact(long long x) {
  PrDoX(sqrt(1e9));
  vector<long long> ans;
  long long i = 0, c = sqrt(x), n = pr.size();
  while (x > 1 and pr[i] <= c and i < n) {
    if (x % pr[i] == 0) {
      x /= pr[i];
      ans.push_back(pr[i]);
      c = sqrt(x);
    } else
      i++;
  }
  if (x != 1) ans.push_back(x);
  return ans;
}
long long n, t, a[501][501], b[501][501], k, l, o, m;
int main() {
  cin >> t;
  while (t--) {
    cin >> n >> m;
    for (long long i = 0; i < n; i++) {
      for (long long j = 0; j < m; j++) cin >> a[i][j];
    }
    for (long long i = 0; i < m; i++) {
      for (long long j = 0; j < n; j++) cin >> b[i][j];
    }
    long long l, x;
    for (long long i = 0; i < n; i++) {
      bool fl = 0;
      for (long long j = 0; j < n; j++) {
        if (a[i][j] == b[0][0]) {
          l = i;
          fl = 1;
          break;
        }
      }
      if (fl == 1) break;
    }
    vector<pair<long long, long long>> v(m);
    for (long long i = 0; i < m; i++) {
      for (long long j = 0; j < m; j++) {
        if (a[l][i] == b[j][0]) {
          v[i] = {i, j};
          break;
        }
      }
    }
    sort(v.begin(), v.end());
    vector<vector<long long>> v1(m, vector<long long>(n));
    for (long long i = 0; i < m; i++) {
      for (long long j = 0; j < n; j++) {
        v1[i][j] = b[v[i].second][j];
      }
    }
    for (long long i = 0; i < n; i++) {
      for (long long j = 0; j < m; j++) {
        cout << v1[j][i] << " ";
      }
      cout << "\n";
    }
  }
  return 0;
}
