#include <bits/stdc++.h>
using namespace std;
const int N = 6005;
const int mod = 1e9 + 7;
const int INF = 0x3f3f3f3f;
int _, n, x[N], y[N], cnt[2][2];
void solve() {
  cin >> n;
  return;
}
int main() {
  cin >> n;
  for (int i = 0; i < n; i++)
    cin >> x[i] >> y[i], x[i] /= 2, y[i] /= 2, cnt[x[i] % 2][y[i] % 2]++;
  long long ans = 0;
  for (int i = 0; i < 2; i++)
    for (int j = 0; j < 2; j++)
      ans += cnt[i][j] * (cnt[i][j] - 1) / 2 * (n - 2) -
             cnt[i][j] * (cnt[i][j] - 1) * (cnt[i][j] - 2) / 6 * 2;
  cout << ans << "\n";
  return 0;
}
