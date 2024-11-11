#include <bits/stdc++.h>
using namespace std;
const int N = 1e3 + 10;
const int MOD = 1e9 + 7;
long long C[N][N];
map<long long, int> mp;
long long a[N], b[N], c[N][N];
int main() {
  for (int i = 0; i < N; i++) {
    C[i][0] = 1;
    for (int j = 1; j <= i; j++) {
      C[i][j] = (C[i - 1][j - 1] + C[i - 1][j]) % MOD;
    }
  }
  int n, m;
  cin >> m >> n;
  while (n--) {
    long long y = 0;
    for (int i = 0; i < m; i++) {
      long long x;
      scanf("%1I64d", &x);
      a[i] |= x << n;
    }
  }
  for (int i = 0; i < m; i++) {
    mp[a[i]]++;
  }
  b[0] = b[1] = 1;
  for (int i = 2; i <= m; i++) {
    for (int j = 0; j < i; j++) {
      (b[i] += C[i - 1][j] * b[i - j - 1]) %= MOD;
    }
  }
  long long ans = 1;
  for (auto it : mp) {
    (ans *= b[it.second]) %= MOD;
  }
  cout << ans << endl;
  return 0;
}
