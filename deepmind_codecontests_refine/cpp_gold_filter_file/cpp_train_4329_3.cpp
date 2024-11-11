#include <bits/stdc++.h>
using namespace std;
map<pair<long long, long long>, long long> M;
long long H1[1000001], H2[1000001], fact[1000001], v[1000001];
;
long long n, m, p;
int main() {
  fact[0] = 1;
  for (long long i = 1; i <= 1000000; ++i) {
    fact[i] = (fact[i - 1] % 1000000007) * (i % 1000000007) % 1000000007;
  }
  cin >> n >> m;
  p = 3;
  for (long long i = 1; i <= m; ++i) {
    H1[i] = 1;
    H2[i] = 1;
  }
  for (long long i = 1; i <= n; ++i) {
    long long cout;
    cin >> cout;
    vector<long long> a;
    for (long long j = 1; j <= cout; ++j) {
      long long x;
      cin >> x;
      if (v[x] == 0) a.push_back(x);
      v[x]++;
    }
    for (long long j = 0; j < a.size(); ++j) {
      H1[a[j]] = ((H1[a[j]]) + (v[a[j]]) * (p)) % 666013;
      H2[a[j]] = ((H2[a[j]]) + (v[a[j]]) * (p)) % 786433;
      v[a[j]] = 0;
    }
    p = ((p) * (1000000007));
  }
  for (long long i = 1; i <= m; ++i) {
    M[make_pair(H1[i], H2[i])]++;
  }
  long long ans = 1;
  for (auto i : M) {
    ans = ((ans % 1000000007) * fact[i.second]) % 1000000007;
  }
  cout << ans << '\n';
  return 0;
}
