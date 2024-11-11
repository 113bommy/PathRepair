#include <bits/stdc++.h>
using namespace std;
#pragma GCC optimize("Ofast")
void init() {
  freopen("cf.inp", "r", stdin);
  freopen("cf.out", "w", stdout);
}
const long long N = 1e6 + 5;
long long n, a[N], b[N], m;
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  long long t;
  cin >> t;
  while (--t) {
    cin >> n >> m;
    for (long long i = 1; i <= n; i++) cin >> a[i];
    for (long long i = 1; i <= m; i++) cin >> b[i];
    for (long long i = 1; i <= n; i++) {
      for (long long j = 1; j <= m; j++) {
        if (a[i] == b[j]) {
          cout << "YES";
          cout << endl;
          cout << "1 " << a[i];
          cout << endl;
          goto x;
        }
      }
    }
    cout << "NO";
    cout << endl;
  x:;
  }
}
