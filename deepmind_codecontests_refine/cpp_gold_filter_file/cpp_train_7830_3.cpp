#include <bits/stdc++.h>
using namespace std;
void boost() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
}
int main() {
  long long i, j, n, t, x, y, ans = 0, cnt = 0, l = 0, m, p, temp, max = 0, k;
  string s;
  boost();
  cin >> n;
  cin >> s;
  temp = -1;
  for (i = 0; i < n; i++) {
    if (s[i] == '(')
      cnt++;
    else
      cnt--;
    if (cnt == 0) {
      if (s[i] == ')')
        temp = i;
      else {
        ans += i - temp;
        temp = i;
      }
    }
  }
  if (cnt != 0)
    cout << "-1";
  else
    cout << ans;
}
