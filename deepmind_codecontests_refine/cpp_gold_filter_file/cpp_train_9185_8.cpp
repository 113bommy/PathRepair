#include <bits/stdc++.h>
using namespace std;
int main() {
  ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
  int T;
  cin >> T;
  while (T--) {
    int N, K;
    cin >> N >> K;
    int a[N];
    for (int i = 0; i < N; i++) {
      cin >> a[i];
    }
    int b[2 * K + 3], c[2 * K + 3];
    memset(b, 0, sizeof b);
    memset(c, 0, sizeof c);
    for (int i = 0; i < N / 2; i++) {
      b[min(a[i], a[N - (i + 1)]) + 1] += 1;
      b[max(a[i], a[N - (i + 1)]) + K + 1] -= 1;
      c[a[i] + a[N - (i + 1)]]++;
    }
    int d[2 * K + 3];
    memset(d, 0, sizeof d);
    for (int i = 0; i < 2 * K + 3; i++) {
      if (i == 0)
        d[i] = b[i];
      else
        d[i] = d[i - 1] + b[i];
    }
    int ans = INT_MAX;
    for (int i = 2; i <= 2 * K; i++) {
      int t1 = c[i];
      int t2 = d[i];
      ans = min(ans, (t2 - t1) + (+N - (2 * t2)));
    }
    cout << ans << '\n';
  }
  return 0;
}
