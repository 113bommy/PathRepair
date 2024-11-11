#include <bits/stdc++.h>
using namespace std;
int main() {
  string s;
  cin >> s;
  int flag = 0;
  for (int i = 1; i < s.size() - 1; i++) {
    if (s[i] == 'A' && s[i + 1] == 'B' && s[i - 1] == 'C') flag++;
    if (s[i] == 'A' && s[i + 1] == 'C' && s[i - 1] == 'B') flag++;
    if (s[i] == 'B' && s[i + 1] == 'A' && s[i - 1] == 'C') flag++;
    if (s[i] == 'B' && s[i + 1] == 'C' && s[i - 1] == 'A') flag++;
    if (s[i] == 'C' && s[i + 1] == 'B' && s[i - 1] == 'A') flag++;
    if (s[i] == 'C' && s[i + 1] == 'A' && s[i - 1] == 'B') flag++;
  }
  if (flag > 0)
    cout << "Yes";
  else
    cout << "No";
}
