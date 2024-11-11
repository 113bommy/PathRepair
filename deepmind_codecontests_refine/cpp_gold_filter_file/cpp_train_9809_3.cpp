#include <bits/stdc++.h>
using namespace std;
int T;
int n, x;
int sum = 0;
char s[100005];
int cnt0 = 0, cnt1 = 0;
int bal;
int tot;
int ans;
int main() {
  cin >> T;
  while (T--) {
    sum = 0;
    cin >> n >> x;
    cnt0 = 0;
    cnt1 = 0;
    ans = 0;
    scanf("%s", s + 1);
    for (int i = 1; i <= n; i++) {
      if (s[i] == '0') cnt0++;
      if (s[i] == '1') cnt1++;
    }
    tot = cnt0 - cnt1;
    for (int i = 1; i <= n; i++) {
      if (tot == 0) {
        if (sum == x) {
          ans = -1;
          break;
        }
      } else if (abs(x - sum) % abs(tot) == 0) {
        if ((x - sum) / tot >= 0) ans++;
      }
      if (s[i] == '0') sum++;
      if (s[i] == '1') sum--;
    }
    cout << ans << '\n';
  }
  return 0;
}
