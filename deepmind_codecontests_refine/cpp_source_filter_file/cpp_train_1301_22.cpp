#include <bits/stdc++.h>
using namespace std;
int num[100001];
int cmp(const int a, const int b) {
  int ta, tb;
  ta = a - (a / 10) * 10;
  tb = b - (b / 10) * 10;
  return ta > tb;
}
int main() {
  int n, k, ans, i;
  cin >> n >> k;
  ans = 0;
  for (i = 1; i <= n; i++) {
    cin >> num[i];
    ans += num[i] / 10;
  }
  sort(num + 1, num + n + 1, cmp);
  for (i = 1; i <= n; i++) {
    if (num[i] % 10 == 0) continue;
    k -= 10 - (num[i] - (num[i] / 10) * 10);
    if (k < 0) break;
    ans++;
  }
  if (k > 0) {
    ans = ans + k / 10 > n * 100 ? n * 100 : ans + k / 10;
  }
  cout << ans << endl;
  return 0;
}
