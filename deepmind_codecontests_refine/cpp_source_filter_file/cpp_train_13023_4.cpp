#include <bits/stdc++.h>
using namespace std;
long long INF = 1e18;
int main() {
  long long n;
  cin >> n;
  vector<long long> a(n), v(n), b(n), c(4), d(4);
  for (long long i = 0; i < 4; i++) {
    c[i] = i;
  }
  for (long long i = 0; i < n; i++) {
    cin >> a[i] >> v[i] >> b[i];
    a[i]--;
    b[i]--;
  }
  for (long long z = 0; z < n; z++) {
    d[a[z]]++;
    d[b[z]]++;
    long long ca = c[a[z]];
    for (long long i = 0; i < 4; i++) {
      if (c[i] == ca) {
        c[i] = c[b[z]];
      }
    }
  }
  bool odd = true;
  for (long long i = 0; i < 4; i++) {
    if (!(d[i] % 2 == 1 && c[i] == c[0])) {
      odd = false;
    }
  }
  long long ans = -INF;
  for (long long y = odd ? 0 : -1; y < n; y++) {
    if (odd && a[y] == b[y]) {
      continue;
    }
    vector<long long> f(4), e(4);
    for (long long i = 0; i < 4; i++) {
      f[i] = i;
    }
    for (long long z = 0; z < n; z++) {
      if (z == y) {
        continue;
      }
      long long fa = f[a[z]];
      for (long long i = 0; i < 4; i++) {
        if (f[i] == fa) {
          f[i] = f[b[z]];
        }
      }
      e[a[z]] += v[z];
      e[b[z]] += v[z];
    }
    for (long long i = 0; i < 4; i++) {
      long long sm = 0;
      for (long long j = 0; j < 4; j++) {
        if (c[j] == i) {
          sm += e[j];
        }
      }
      sm /= 2;
      ans = max(ans, sm);
    }
  }
  cout << ans << endl;
}
