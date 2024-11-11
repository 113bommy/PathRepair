#include <bits/stdc++.h>
using namespace std;
const int MAX = 4002;
int v[MAX], sum[9 * MAX], N;
char s[MAX];
int main() {
  int a;
  while (scanf("%d", &a) == 1) {
    scanf("%s", s);
    N = strlen(s), v[0] = 0;
    for (int x = 0; x < N; x++) v[x + 1] = (s[x] - '0') + v[x];
    memset(sum, 0, sizeof(sum));
    for (int x = 1; x <= N; x++)
      for (int y = x; y <= N; y++) {
        int Sxy = v[y] - v[x - 1];
        if (Sxy >= 9 * MAX || Sxy < 0) continue;
        sum[Sxy]++;
      }
    long long ans = 0LL;
    for (int x = 1; x <= N; x++)
      for (int y = x; y <= N; y++) {
        int Sxy = v[y] - v[x - 1];
        if (!a) {
          if (!Sxy)
            ans += 1ll * ((1LL * N * (N + 1LL)) / 2LL);
          else
            ans += (1LL * sum[0]);
          continue;
        }
        if (!Sxy) continue;
        if (a % Sxy || a / Sxy >= 9 * MAX) continue;
        ans += (1LL * sum[a / Sxy]);
      }
    cout << ans << endl;
  }
  return 0;
}
