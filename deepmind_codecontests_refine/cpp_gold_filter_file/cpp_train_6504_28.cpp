#include <bits/stdc++.h>
using namespace std;
int w[2500];
int now[2500], f[2500];
void dp(int x, int L, int R) {
  if (L == R) {
    now[x] = w[x];
    f[x] = 0;
    return;
  }
  int mid = (L + R) >> 1;
  dp(x << 1, L, mid);
  dp(x << 1 | 1, mid + 1, R);
  now[x] = max(now[x << 1], now[x << 1 | 1]);
  f[x] = f[x << 1] + f[x << 1 | 1] + now[x] * 2 - now[x << 1] - now[x << 1 | 1];
  now[x] += w[x];
}
int main() {
  int n, i, cf;
  cin >> n;
  cf = (1 << n + 1) - 1;
  for (i = 2; i <= cf; i++) scanf("%d", &w[i]);
  dp(1, 1, (1 << n));
  cout << f[1] << endl;
  return 0;
}
