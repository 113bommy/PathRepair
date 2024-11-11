#include <bits/stdc++.h>
using namespace std;
int main() {
  string s;
  cin >> s;
  int sum = 0;
  for (int i = 0; i < s.size(); i++)
    if ((int)(s[i]) <= 122 && (int)(s[i]) >= 97) sum++;
  if (sum > 1 || sum < 2 && (int)(s[0]) <= 90 && 65 <= (int)(s[0]))
    cout << s << endl;
  else {
    for (int i = 0; i < s.size(); i++) {
      if ((int)(s[i]) <= 122 && (int)(s[i]) >= 97)
        cout << (char)((int)(s[i]) - 32);
      else
        cout << (char)((int)(s[i]) + 32);
    }
    cout << endl;
  }
  return 0;
}
