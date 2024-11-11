#include <bits/stdc++.h>
using namespace std;
const int maxn = 3e5 + 10;
int n;
long long Ans;
long long b[maxn][2], a[maxn][2], ans[maxn][2], ans2[maxn][2];
int main() {
  cin >> n;
  for (int i = 0; i < 2; i++)
    for (int j = 1; j <= n; j++) cin >> b[j][i];
  for (int i = 1; i <= n; i++) {
    a[i][0] = 1LL * (i - 1) * b[i][0];
    a[i][1] = 1LL * (-i + 2 * n) * b[i][1];
  }
  for (int i = 1; i <= n; i++) {
    ans[i][0] = ans[i - 1][0] + a[i][0] + a[i][1];
    ans2[i][0] = ans2[i - 1][0] + b[i][0] + b[i][1];
  }
  for (int i = 1; i <= n; i++) {
    a[i][1] = b[i][1] * i;
    a[i][0] = b[i][0] * (-i + 2 * n + 1);
  }
  ans[1][1] = b[1][1];
  for (int i = 2; i <= n; i++) {
    ans[i][1] = ans[i - 1][1] + a[i][0] + a[i][1];
  }
  long long tmp = b[1][1], pos = 2;
  for (int i = 2; i <= n; i++) {
    if (i & 1 == 0) {
      if (i != n)
        Ans = max(Ans, tmp + ans[n][(i + 1) % 2] - ans[i - 1][(i + 1) % 2] +
                           1LL * (i - 2) * (ans2[n][0] - ans2[i - 1][0]));
      tmp += (pos++) * b[i][1];
      tmp += (pos++) * b[i][0];
    } else {
      if (i != n)
        Ans = max(Ans, tmp + ans[n][(i + 1) % 2] - ans[i - 1][(i + 1) % 2] +
                           1LL * (i - 1) * (ans2[n][0] - ans2[i - 1][0]));
      tmp += (pos++) * b[i][0];
      tmp += (pos++) * b[i][1];
    }
  }
  Ans = max(Ans, max(tmp, max(ans[n][0], ans[n][1])));
  cout << Ans;
  return 0;
}
