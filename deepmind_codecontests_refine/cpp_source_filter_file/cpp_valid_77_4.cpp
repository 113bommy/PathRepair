#include <bits/stdc++.h>
using namespace std;
const int N = 1e6, mod = 1e9 + 7;
int n, m, ans[4 * N + 1];
void input() {
  cin >> n >> m;
  ans[1] = 1;
  for (int i = 2; i <= n; i++) {
    ans[i] = (ans[i] + 2LL * ans[i - 1] + 1) % m;
    if (i == 2) ans[i]--;
    for (int j = 2 * i; j <= n; j += i)
      ans[j] = (ans[j] + ans[i] - ans[i - 1] + m) % m;
  }
  cout << ans[n] << endl;
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  input();
  return 0;
}
