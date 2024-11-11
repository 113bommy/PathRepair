#include <bits/stdc++.h>
using namespace std;
void null() { return; }
const long long maxn = 2e6 + 7, N = 1e6, INF = 3e18 + 9237, mod = 1e9 + 7;
bool mrk[maxn];
long long a[101], b[101];
void solve(long long ind) {
  memset(mrk, false, sizeof(mrk));
  memset(a, 0, sizeof(a));
  memset(b, 0, sizeof(b));
  long long n;
  cin >> n;
  for (long long i = 0; i < n; i++) cin >> a[i];
  sort(a, a + n);
  for (long long i = 0; i < n; i++) {
    for (long long j = i + 1; j < n; j++) {
      mrk[a[j] - a[i]] = true;
    }
  }
  long long k = 1;
  for (long long i = 0; i < n; i++) {
    if (k > N) return cout << "NO\n", null();
    b[i] = k;
    bool chck = true;
    while (chck && k <= N) {
      chck = false;
      k++;
      for (long long j = 0; j < i; j++) {
        if (mrk[k - b[j]]) {
          chck = true;
          break;
        }
      }
    }
  }
  cout << "YES\n";
  for (long long i = 0; i < n; i++) cout << b[i] << ' ';
  cout << '\n';
}
int32_t main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  long long t;
  cin >> t;
  for (long long i = 0; i < t; i++) solve(i);
}
