#include <bits/stdc++.h>
using namespace std;
void err(istream_iterator<string> it) {}
template <typename T, typename... Args>
void err(istream_iterator<string> it, T a, Args... args) {
  cerr << "[ " << *it << " = " << a << " ] ";
  err(++it, args...);
}
signed main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  long long int n, m, k;
  cin >> n >> m >> k;
  long long int a[n], b[m];
  for (long long int i = 0; i < n; i++) {
    cin >> a[i];
  }
  for (long long int i = 0; i < m; i++) {
    cin >> b[i];
  }
  sort(a, a + n, greater<long long int>());
  sort(b, b + m, greater<long long int>());
  function<bool(long long int[], long long int[], long long int, long long int)>
      new_lexi = [&](long long int a[], long long int b[], long long int n,
                     long long int m) {
        for (long long int i = 0; i < min(m, n); i++) {
          if (a[i] > b[i]) {
            return true;
          }
        }
        if (n > m) return true;
        return false;
      };
  cout << (new_lexi(a, b, n, m) ? "YES\n" : "NO\n");
  return 0;
}
