#include <bits/stdc++.h>
#pragma comment(linker, "/STACK:256000000000000000000000000000000")
using namespace std;
long long n, m, ans = 0;
long long A[55][55];
inline long long f(long long a) { return (1ll << a) - 1; }
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  cin >> n >> m;
  for (register long long i = 1; i <= n; ++i) {
    for (register long long j = 1; j <= m; ++j) {
      cin >> A[i][j];
    }
  }
  for (register long long i = 1; i <= n; ++i) {
    long long a = 0;
    for (register long long j = 1; j <= m; ++j) {
      a += (A[i][j] == 1);
    }
    ans += f(a);
    a = m - a;
    ans += f(a);
  }
  for (register long long i = 1; i <= m; ++i) {
    long long a = 0;
    for (register long long j = 1; j <= n; ++j) {
      a += (A[j][i] == 1);
    }
    ans += f(a);
    a = n - a;
    ans += f(a);
  }
  cout << ans - m * n;
}
