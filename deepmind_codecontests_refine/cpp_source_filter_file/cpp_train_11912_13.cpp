#include <bits/stdc++.h>
using namespace std;
int main() {
  string s;
  string ans;
  cin >> s;
  int val[10];
  for (int i = 0; i < 10; i++) val[i] = 0;
  int size = s.length();
  for (int i = 0; i < size; i++) {
    val[s[i] - '0'] += 1;
  }
  val[1] -= 1;
  val[6] -= 1;
  val[8] -= 1;
  val[9] -= 1;
  for (int i = 1; i < 10; i++) {
    for (int j = 0; j < val[i]; j++) {
      ans += (i + '0');
    }
  }
  int size2 = ans.length();
  int mod = 0;
  int fact = 10000 % 7;
  for (int i = (size2 - 1); i >= 0; i--) {
    mod += (fact * ((int)(ans[i] - '0')));
    mod = mod % 7;
    fact = (fact * 10) % 7;
  }
  if (mod) mod = (7 - mod);
  string tp[7];
  tp[0] = "1869";
  tp[1] = "1968";
  tp[2] = "1689";
  tp[3] = "1698";
  tp[4] = "8691";
  tp[5] = "1986";
  tp[6] = "1896";
  ans += tp[mod];
  for (int i = 0; i < val[0]; i++) ans += '0';
  cout << ans << "\n";
  return 0;
}
