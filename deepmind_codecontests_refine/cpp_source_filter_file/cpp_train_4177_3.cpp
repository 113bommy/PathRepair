#include <bits/stdc++.h>
using namespace std;
const int MAX = 300010;
int N;
int B[MAX];
int num[MAX][2], sum[MAX];
int main() {
  int i, j, k;
  cin >> N;
  for (i = 1; i <= N; i++) {
    long long a;
    scanf("%lld", &a);
    while (a > 0) {
      if (a & 1) B[i]++;
      a >>= 1;
    }
  }
  for (i = 1; i <= N; i++) {
    sum[i] = sum[i - 1] + B[i];
    int parity = sum[i] % 2;
    num[i][parity]++;
    for (k = 0; k < 2; k++) num[i][k] += num[i - 1][k];
  }
  long long ans = 0;
  for (i = 1; i <= N; i++) {
    int s = B[i], mx = B[i];
    for (j = i + 1; j <= min(i + 60, N); j++) {
      s += B[j];
      mx = max(mx, B[j]);
      if (s % 2 == 0 && s >= 2 * mx) ans++;
    }
    if (i + 61 <= N) {
      int parity = sum[i - 1] % 2;
      ans += num[N][parity] - num[i + 61][parity];
    }
  }
  cout << ans << endl;
  return 0;
}
