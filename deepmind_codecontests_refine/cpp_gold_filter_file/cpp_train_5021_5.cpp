#include <bits/stdc++.h>
using namespace std;
char s[1000005];
int n;
int main() {
  cin >> n;
  scanf("%s", s + 1);
  int now = 0, ans = 0;
  for (int i = 1; i <= n; i++) {
    if (s[i] == '(')
      now++;
    else {
      now--;
      if (now == -1) ans++;
    }
    if (now < 0) ans++;
  }
  if (now != 0)
    cout << -1 << endl;
  else
    cout << ans << endl;
}
