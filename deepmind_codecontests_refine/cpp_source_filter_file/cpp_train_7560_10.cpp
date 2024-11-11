#include <bits/stdc++.h>
using namespace std;
int n, m;
string s;
int dp1[110000], dp2[110000], replacements = 0, len1 = 0, mod = 0,
                              consec_repl = 0;
char prev1 = 'a';
int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  cin >> n;
  cin >> s;
  cin >> m;
  dp1[0] = dp2[0] = 0;
  for (int i = 0; i < s.size(); i++) {
    if (s[i] == '?') {
      replacements++;
      if (s[i] == prev1)
        consec_repl++;
      else
        consec_repl = 1;
    }
    if (i >= m and s[i - m] == '?') replacements--;
    if ((s[i] == 'a' and mod == 1) or (s[i] == 'b' and mod == 0)) {
      if (s[i] == 'a') {
        len1 = 2 * (consec_repl / 2) + 1;
        mod = 1;
        consec_repl = 0;
      } else {
        if (consec_repl % 2)
          len1 = consec_repl + 1;
        else
          len1 = consec_repl;
        mod = 0;
        consec_repl = 0;
      }
    } else {
      len1++;
      mod++;
      mod %= 2;
      if (s[i] != '?') consec_repl = 0;
    }
    if (i >= m - 1 and (m % 2 == mod or consec_repl == m)) {
      if (len1 >= m) {
        if (1 + dp1[i - m + 1] > dp1[i]) {
          dp1[i + 1] = 1 + dp1[i - m + 1];
          dp2[i + 1] = dp2[i - m + 1] + replacements;
        } else if (1 + dp1[i - m + 1] == dp1[i]) {
          dp1[i + 1] = dp1[i];
          dp2[i + 1] = min(dp2[i - m + 1] + replacements, dp2[i]);
        } else {
          dp1[i + 1] = dp1[i];
          dp2[i + 1] = dp2[i];
        }
      } else {
        dp1[i + 1] = dp1[i];
        dp2[i + 1] = dp2[i];
      }
    } else {
      dp1[i + 1] = dp1[i];
      dp2[i + 1] = dp2[i];
    }
    prev1 = s[i];
  }
  cout << dp2[n] << "\n";
}
