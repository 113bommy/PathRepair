#include <bits/stdc++.h>
using namespace std;
long long n, m, k, x, t;
string s, ans[1011], pri, cur, s1;
bool bo = true;
void calc() {
  s1 = "9999";
  for (int i = 0; i < 4; i++) {
    for (char j = '0'; j <= '9'; j++) {
      cur = s;
      cur[i] = j;
      if (cur < "1000" || cur > "2011") continue;
      if (cur < pri) continue;
      if (i == 0 && j != '1' && i == 0 && j != '2') continue;
      s1 = min(s1, cur);
    }
  }
}
int main() {
  cin >> n;
  pri = "0";
  for (int i = 1; i <= n; i++) {
    cin >> s;
    calc();
    if (pri > s1 || s1 > "2011" || s1 < "1000") bo = false;
    pri = ans[i] = s1;
  }
  if (bo)
    for (int i = 1; i <= n; i++) cout << ans[i] << "\n";
  else
    cout << "No solution";
}
