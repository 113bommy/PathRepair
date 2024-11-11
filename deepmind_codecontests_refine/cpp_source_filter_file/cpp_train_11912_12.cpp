#include <bits/stdc++.h>
using namespace std;
string s, a;
int find_mod(int i) {
  if (i == 1) {
    int temp = 10 * (s[0] - '0') + (s[1] - '0');
    return temp % 7;
  }
  return ((find_mod(i - 1) * (10 % 7)) % 7 + (s[i] - '0') % 7) % 7;
}
int main() {
  int i, j = 0;
  string ans[10], zero;
  ans[6] = "1896", ans[5] = "1986", ans[4] = "1698", ans[0] = "1869",
  ans[2] = "9816", ans[1] = "6189", ans[3] = "6198";
  cin >> s;
  int hash[11] = {0};
  for (i = 0; i < s.length(); i++) {
    if (s[i] == '1' && hash[1] == 0) {
      hash[1]++;
      continue;
    }
    if (s[i] == '8' && hash[8] == 0) {
      hash[8]++;
      continue;
    }
    if (s[i] == '6' && hash[6] == 0) {
      hash[6]++;
      continue;
    }
    if (s[i] == '9' && hash[9] == 0) {
      hash[9]++;
      continue;
    }
    if (s[i] == '0') {
      zero += s[i];
      continue;
    }
    a += s[i];
  }
  s = a;
  s += "0000";
  int temp = find_mod(s.length() - 1);
  string ret;
  ret = a + ans[7 - temp] + zero;
  cout << ret;
  return 0;
}
