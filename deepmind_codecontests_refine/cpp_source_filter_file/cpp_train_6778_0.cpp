#include <bits/stdc++.h>
using namespace std;
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  long long n, m;
  cin >> n >> m;
  map<long long, long long> cnt;
  set<long long> s;
  long long r = n % m;
  long long d = n / m;
  long long dd = d;
  d = d * 1ll * m;
  if (n < m) {
    for (long long i = 1; i <= n; i++) {
      long long p = i * 1ll * i;
      long long md = p % m;
      s.insert(md);
      cnt[md]++;
    }
    long long ans = 0;
    for (auto it : s) {
      long long a = it;
      long long b;
      if (it == 0) {
        b = 0;
      } else {
        b = m - a;
      }
      a = cnt[a];
      b = cnt[b];
      ans += (a * 1ll * b);
    }
    cout << ans << '\n';
    return 0;
  }
  for (long long i = 1; i <= m; i++) {
    long long p = i * 1ll * i;
    s.insert(p % m);
    long long md = p % m;
    cnt[md]++;
  }
  for (auto it : s) {
    cnt[it] = cnt[it] * 1ll * dd;
  }
  for (long long i = d + 1; i <= m + r; i++) {
    long long p = i * 1ll * i;
    long long md = p % m;
    cnt[md]++;
  }
  long long ans = 0;
  for (auto it : s) {
    long long a = it;
    long long b = 0;
    if (a == 0) {
      b = 0;
    } else {
      b = m - a;
    }
    a = cnt[a];
    b = cnt[b];
    ans += (a * 1ll * b);
  }
  cout << ans << '\n';
  return 0;
}
