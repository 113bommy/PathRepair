#include <bits/stdc++.h>
int main() {
  std ::string s;
  std ::cin >> s;
  unsigned long long summ = 0;
  unsigned long long tmp1 = 0;
  unsigned long long tmp2 = 0;
  unsigned long long tmp3 = 0;
  unsigned long long summTmp = 0;
  if (s.size() > 21) {
    std ::cout << -1;
    return 0;
  }
  for (int i = 1; i < s.size(); i++) {
    for (int j = i + 1; j < s.size(); j++) {
      tmp1 = 0;
      tmp2 = 0;
      tmp3 = 0;
      summTmp = 0;
      if ((s[0] != '0' || i == 1) && (s[i] != '0' || j - i == 1) &&
          (s[j] != '0' || s.size() - j == 1)) {
        for (int k = 0; k < i; k++) {
          tmp1 *= 10;
          tmp1 += s[k] - '0';
        }
        for (int k = i; k < j; k++) {
          tmp2 *= 10;
          tmp2 += s[k] - '0';
        }
        for (int k = j; k < s.size(); k++) {
          tmp3 *= 10;
          tmp3 += s[k] - '0';
        }
        if (tmp1 <= 1000000 && tmp2 <= 1000000 && tmp3 <= 1000000) {
          summTmp = tmp1 + tmp2 + tmp3;
          if (summTmp > summ) summ = summTmp;
        }
      }
    }
  }
  if (summ == 0 && s.size() != 3)
    std ::cout << -1;
  else
    std ::cout << summ;
  return 0;
}
