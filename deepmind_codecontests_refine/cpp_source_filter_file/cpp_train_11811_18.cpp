#include <bits/stdc++.h>
using namespace std;
const long long M = 1e9 + 7;
const long long MAXN = 10000001;
const long long INF = 1e18;
void err(istream_iterator<string> it) {}
template <typename T, typename... Args>
void err(istream_iterator<string> it, T a, Args... args) {
  cerr << *it << " = " << a << '\n';
  err(++it, args...);
}
int32_t main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  long long n;
  cin >> n;
  long long cnta[100000];
  memset(cnta, 0, sizeof(cnta));
  long long p;
  for (long long i = 1; i <= n - 1; ++i) {
    cin >> p;
    cnta[p] = 1;
  }
  for (long long i = 1; i <= n; ++i) {
    if (cnta[i] == 0) {
      cout << i << '\n';
      return 0;
    }
  }
}
