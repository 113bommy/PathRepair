#include <bits/stdc++.h>
using namespace std;
void solve() {
  string s;
  cin >> s;
  int len_s = s.length();
  bool flag_a = false;
  bool flag_b = false;
  bool flag_c = false;
  for (int i = 0; i < len_s - 1; i++) {
    if (!flag_c && i < len_s - 2 &&
        ((s[i] == 'A' && s[i + 1] == 'B' && s[i + 2] == 'A') ||
         (s[i] == 'B' && s[i + 1] == 'A' && s[i + 2] == 'B'))) {
      i++;
      i++;
      flag_c = true;
    }
    if (!flag_a && s[i] == 'A' && s[i + 1] == 'B') {
      i++;
      flag_a = true;
    } else if (!flag_b && s[i] == 'B' && s[i + 1] == 'A') {
      i++;
      flag_b = true;
    }
  }
  if (flag_c && !flag_b)
    flag_b = true;
  else if (flag_c && !flag_a)
    flag_a = true;
  if (flag_a && flag_b)
    cout << "YES" << endl;
  else
    cout << "NO" << endl;
}
int main(void) {
  solve();
  return 0;
}
