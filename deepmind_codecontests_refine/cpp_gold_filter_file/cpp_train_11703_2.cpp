#include <bits/stdc++.h>
using namespace std;
long long mod = 998244353;
signed main() {
  long long a;
  cin >> a;
  string s;
  cin >> s;
  long long n = s.length();
  long long c[n];
  c[0] = s[0] - '0';
  for (long long i = 1; i < n; i++) {
    c[i] = c[i - 1] + (s[i] - '0');
  }
  vector<long long> cnt(c[n - 1] + 1);
  for (long long i = 0; i < n; i++) {
    for (long long j = i; j < n; j++) {
      long long sumochka = c[j] - (i - 1 < 0 ? 0 : c[i - 1]);
      cnt[sumochka]++;
    }
  }
  long long res = 0;
  for (long long i = 0; i < n; i++) {
    for (long long j = i; j < n; j++) {
      long long sumochka = c[j] - (i - 1 < 0 ? 0 : c[i - 1]);
      if (!a && !sumochka) {
        res += n * (n + 1) / 2;
      }
      if (!sumochka) {
        continue;
      }
      if (a % sumochka == 0) {
        if ((a / sumochka) <= c[n - 1]) {
          res += cnt[a / sumochka];
        }
      }
    }
  }
  cout << res;
}
