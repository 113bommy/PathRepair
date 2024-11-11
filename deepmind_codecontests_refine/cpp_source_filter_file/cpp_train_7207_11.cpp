#include <bits/stdc++.h>
using namespace std;
int t[105], s[105], ans[105];
void ask(int x, int i) {
  cout << "+ " << x << endl;
  cin >> t[i] >> s[i];
}
int calc(int x) {
  int i = 1;
  while (1) {
    if (i * (i - 1) / 2 == x) return i;
    ++i;
  }
}
int main() {
  ios::sync_with_stdio(0);
  cin.tie(0), cout.tie(0);
  int n;
  cin >> n;
  cin >> t[0] >> s[0];
  memset(ans, -1, sizeof ans);
  for (int i = 1; i <= n - 1; ++i) {
    ask(i, i);
  }
  ask(1, n);
  for (int i = n; i >= 1; --i) t[i] -= t[i - 1], s[i] -= s[i - 1];
  ans[1] = t[n] - t[1];
  for (int i = 2; i <= n - 1; ++i) {
    if (t[i]) ans[i] = calc(i);
  }
  if (ans[3] == -1) ans[3] = (s[2] > 0);
  if (ans[2] == -1) ans[2] = s[n] / (ans[3] + 1) - 1;
  for (int i = 3; i <= n - 2; ++i) {
    if (ans[i + 1] == -1) {
      s[i] -= (ans[i - 1] + 1) * (ans[i - 2] + 1);
      ans[i + 1] = (s[i] > 0);
    }
  }
  ans[n] = (s[n - 1] - (ans[n - 2] + 1) * (ans[n - 3] + 1)) / (ans[n - 2] + 1);
  cout << "!";
  for (int i = 1; i <= n; ++i) cout << ans[i] << ' ';
  cout << '\n';
  return 0;
}
