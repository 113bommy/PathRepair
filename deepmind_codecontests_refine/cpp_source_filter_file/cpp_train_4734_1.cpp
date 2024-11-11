#include <bits/stdc++.h>
using namespace std;
int main() {
  string s, vokal = "aiueo";
  getline(cin, s);
  std::transform(s.begin(), s.end(), s.begin(), ::tolower);
  char last;
  for (int i = 0; i < s.length(); i++) {
    if (s[i] >= 'a' && s[i] <= 'z') last = s[i];
  }
  if (vokal.find(last) != -1)
    cout << "YES" << endl;
  else
    cout << "NO" << endl;
  return 0;
}
