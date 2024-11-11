#include <bits/stdc++.h>
using namespace std;
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  int n;
  string s;
  cin >> n >> s;
  if (s.size() == 1 && s[0] == '0') {
    cout << "No" << endl;
    return 0;
  }
  if ((s[0] == '0' && s[1] == '0') ||
      (s[s.size() - 1] == '0' && s[s.size() - 2] == '0')) {
    cout << "No" << endl;
    return 0;
  }
  for (int i = 0; i < s.size() - 1; i++) {
    if ((s[i] == '1' && s[i + 1] == '1') ||
        (s[i] == '0' && s[i + 1] == '0' && s[i + 2] == '0')) {
      cout << "No" << endl;
      return 0;
    }
  }
  cout << "Yes" << endl;
  return 0;
}
