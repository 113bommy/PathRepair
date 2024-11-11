#include <bits/stdc++.h>
using namespace std;
const int maxn = 500000 + 5;
long long sum[maxn];
long long cnt[maxn];
int MAIN() {
  int n;
  cin >> n;
  long long v;
  for (int i = 1; i <= n; i++) {
    cin >> v;
    sum[i] = sum[i - 1] + v;
  }
  if (n < 3 || sum[n] % 3 != 0) {
    cout << 0 << endl;
    return 0;
  }
  long long base = sum[n] / 3;
  for (int i = n - 1; i >= 2; i--) {
    if (sum[i] == base * 2) {
      cnt[i] = cnt[i + 1] + 1;
    } else {
      cnt[i] = cnt[i + 1];
    }
  }
  int ans = 0;
  for (int i = 1; i <= n - 2; i++) {
    if (sum[i] == base) {
      ans += cnt[i + 1];
    }
  }
  cout << ans << endl;
  return 0;
}
int main() {
  ios ::sync_with_stdio(false);
  cout << fixed << setprecision(16);
  return MAIN();
}
