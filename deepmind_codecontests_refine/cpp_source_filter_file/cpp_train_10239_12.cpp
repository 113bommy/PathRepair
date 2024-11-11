#include <bits/stdc++.h>
using namespace std;
const int N = 1e5 + 7;
const long long INF = 1E18;
long long dpL[N][2], dpR[N][2];
int seg[N];
int main() {
  int n;
  scanf("%d", &n);
  for (int i = 1; i <= n; i++) scanf("%d", &seg[i]);
  memset(dpL, 0, sizeof dpL);
  memset(dpR, 0, sizeof dpR);
  for (int i = 2; i <= n; i++) {
    if (seg[i - 1] > 1)
      dpL[i][1] =
          dpL[i - 1][1] + ((seg[i - 1] & 1) ? seg[i - 1] - 1 : seg[i - 1]);
    else
      dpL[i][1] = 0;
    dpL[i][0] = max(dpL[i - 1][0], dpL[i - 1][1]) +
                ((seg[i - 1] & 1) ? seg[i - 1] : seg[i - 1] - 1);
    dpL[i][0] = max(dpL[i][0], dpL[i][1]);
  }
  for (int i = n - 1; i >= 0; i--) {
    if (seg[i] > 1)
      dpR[i][1] = dpR[i - 1][1] + ((seg[i] & 1) ? seg[i] - 1 : seg[i]);
    else
      dpR[i][1] = 0;
    dpR[i][0] = max(dpR[i + 1][0], dpR[i + 1][1]) +
                ((seg[i] & 1) ? seg[i] : seg[i] - 1);
    dpR[i][0] = max(dpR[i][0], dpR[i][1]);
  }
  long long maxAns = -1;
  for (int i = 1; i <= n; i++) {
    long long ans = max(dpL[i][1] + dpR[i][0], dpL[i][0] + dpR[i][1]);
    maxAns = max(ans, maxAns);
  }
  cout << maxAns << endl;
}
