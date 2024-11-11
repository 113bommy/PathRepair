#include <bits/stdc++.h>
using namespace std;
int main() {
  string s;
  cin >> s;
  int b = s.find("^");
  int sum = 0, sum1 = 0;
  for (int i = 0; i < b; i++) {
    if (s[i] != '=') {
      int t = (int)s[i];
      t -= 48;
      sum = sum + (b - i) * t;
    }
  }
  for (int i = b + 1; i < s.length(); i++) {
    if (s[i] != '=') {
      int t = (int)s[i];
      t -= 48;
      sum1 = sum1 + (i - b) * t;
    }
  }
  if (sum > sum1)
    cout << "left";
  else if (sum1 > sum)
    cout << "right";
  else
    cout << "balance";
  return 0;
}
