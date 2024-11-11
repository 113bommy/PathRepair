#include <bits/stdc++.h>
using namespace std;
string s;
int main() {
  cin >> s;
  string s1, s2, s3;
  if (s.length() < 3) {
    cout << -1;
    return 0;
  }
  long long so1, so2, so3, res = -1;
  for (int i = 0; i < s.length() - 2; i++)
    for (int j = i + 1; j < s.length() - 1; j++) {
      s1 = "";
      s2 = "";
      s3 = "";
      so1 = 0;
      so2 = 0;
      so3 = 0;
      if ((i + 1 > 7) || (j - (i + 1) + 1 > 7) ||
          (s.length() - 1 - (j + 1) + 1 > 7))
        continue;
      for (int t = 0; t <= i; t++) {
        s1 += s[t];
        so1 = so1 * 10 + s[t] - '0';
      }
      for (int t = i + 1; t <= j; t++) {
        s2 += s[t];
        so2 = so2 * 10 + s[t] - '0';
      }
      for (int t = j + 1; t < s.length(); t++) {
        s3 += s[t];
        so3 = so3 * 10 + s[t] - '0';
      }
      if (((s1.length() >= 2) && (s1[0] == '0')) ||
          ((s2.length() >= 2) && (s2[0] == '0')) ||
          ((s3.length() >= 2) && (s3[0] == '0')))
        continue;
      if ((so1 <= 1000000) && (so2 <= 1000000) && (so3 <= 1000000))
        res = max(res, so1 + so2 + so3);
    }
  cout << res;
}
