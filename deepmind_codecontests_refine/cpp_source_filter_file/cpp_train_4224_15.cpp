#include <bits/stdc++.h>
using namespace std;
long long n, p[10005], c[10005], cc;
long long f[2][10005], t;
int main() {
  cin >> n >> cc;
  for (int i = 1; i <= n; i++) {
    cin >> p[i];
  }
  for (int i = 1; i <= n; i++) {
    cin >> c[i];
  }
  for (long long i = 1; i <= n; i++) {
    for (long long j = 1; j < i; j++) {
      f[t][j] = min(f[t ^ 1][j] + cc * j + c[i], f[t ^ 1][j - 1] + p[i]);
    }
    f[t][0] = f[t ^ 1][0] + p[i];
    f[t][i] = f[t ^ 1][i - 1] + p[i];
    t ^= 1;
  }
  long long ans = 1e17;
  for (int i = 0; i <= n; i++) {
    ans = min(ans, f[t ^ 1][i]);
  }
  cout << ans << endl;
  return 0;
}
