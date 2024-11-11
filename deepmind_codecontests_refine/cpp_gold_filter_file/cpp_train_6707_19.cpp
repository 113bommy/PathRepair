#include <bits/stdc++.h>
using namespace std;
int main() {
  string s;
  cin >> s;
  int n(0), i(0), t(0), e(0);
  for (int j = 0; j < s.length(); j++) {
    if (s[j] == 'n')
      ++n;
    else if (s[j] == 'i')
      ++i;
    else if (s[j] == 't')
      ++t;
    else if (s[j] == 'e')
      ++e;
  }
  int min = e / 3;
  if (i < min) min = i;
  if (t < min) min = t;
  if ((n - 1) / 2 < min) min = (n - 1) / 2;
  cout << min;
  return 0;
}
