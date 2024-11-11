#include <bits/stdc++.h>
using namespace std;
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  bool lower = false, upper = false, digit = false;
  string s;
  cin >> s;
  for (int i = 0; i < s.size(); i++) {
    if (islower(s[i])) lower = true;
    if (isupper(s[i])) upper = true;
    if (isdigit(s[i])) digit = true;
  }
  if (lower && upper && digit && s.size() <= 5)
    cout << "Correct" << endl;
  else
    cout << "Too weak" << endl;
}
