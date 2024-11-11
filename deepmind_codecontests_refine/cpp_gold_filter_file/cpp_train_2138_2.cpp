#include <bits/stdc++.h>
using namespace std;
int main() {
  string s;
  int sum = 0;
  cin >> s;
  for (int i = 0; i < s.size(); i++) {
    if (s[i] >= 'A' && s[i] <= 'Z') sum += s[i] - '@';
    if (s[i] >= 'a' && s[i] <= 'z') sum -= s[i] + 1 - 'a';
  }
  cout << sum << endl;
  return 0;
}
