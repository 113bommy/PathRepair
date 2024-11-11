#include <bits/stdc++.h>
using namespace std;
int n, k, a[320000];
long long f[5200][5200];
int main() {
  ios_base::sync_with_stdio(false);
  cin >> n >> k;
  for (int i = 1; i <= n; i++) cin >> a[i];
  sort(a + 1, a + n + 1);
  int sl1 = n % k;
  int sl2 = k - sl1;
  int sp = n / k;
  memset(f, 126, sizeof(f));
  f[0][0] = 0;
  for (int i = 1; i <= sl2; i++) {
    int pos = i * sp;
    f[0][i] = f[0][i - 1] + a[pos] - a[pos - sp + 1];
  }
  for (int i = 1; i <= sl1; i++) {
    int pos = i * sp + 1;
    f[i][0] = f[i - 1][0] + a[pos] - a[pos - sp];
  }
  for (int i = 1; i <= sl1; i++)
    for (int j = 1; j <= sl2; j++) {
      int pos = i * (sp + 1) + j * sp;
      f[i][j] = min(f[i][j], min(f[i - 1][j] + a[pos] - a[pos - sp],
                                 f[i][j - 1] + a[pos] - a[pos - sp + 1]));
    }
  cout << f[sl1][sl2];
  return 0;
}
