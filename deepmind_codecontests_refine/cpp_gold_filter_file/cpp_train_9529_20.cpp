#include <bits/stdc++.h>
using namespace std;
const int N = 200035;
long long a[N];
long long b[N];
long long c[N];
const long long INF = 1e17;
bool can[N];
int main() {
  ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
  int n, k;
  cin >> n >> k;
  ++n;
  for (int i = 0; i < n; ++i) cin >> a[i], c[i] = a[i];
  for (int i = 0; i < N; ++i) {
    if (a[i] % 2 == 0) {
      a[i + 1] += a[i] / 2;
      a[i] = 0;
    }
  }
  int ans = 0;
  b[N - 1] = -a[N - 1];
  can[N - 1] = 1;
  for (int i = N - 2; i >= 0; --i) {
    b[i] = (b[i + 1] * 2) - a[i];
    can[i] = 1;
    if (abs(b[i]) > INF) break;
  }
  for (int i = 0; i < n; ++i) {
    if (can[i]) {
      b[i] += c[i];
      ans += abs(b[i]) <= k && (i != n - 1 or b[i]);
    }
    if (a[i]) break;
  }
  cout << ans;
}
