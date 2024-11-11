#include <bits/stdc++.h>
using namespace std;
const int maxn = 5e5 + 5;
int N, a[maxn];
long long sum[maxn];
signed main(void) {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  cin >> N;
  int h = (N + 1) / 2;
  for (int i = 1; i <= h; ++i) {
    cin >> a[i];
  }
  int x;
  cin >> x;
  for (int i = h + 1; i <= N; ++i) a[i] = x;
  for (int i = 1; i <= N; ++i) sum[i] = sum[i - 1] + a[i];
  long long mx = -1e18;
  for (int i = 0; i < h; ++i) {
    mx = max(mx, sum[i] + 1ll * x * (N - i) - sum[N]);
    if (mx < 1ll * x * (N - i)) {
      cout << N - i;
      return 0;
    }
  }
  cout << -1;
}
