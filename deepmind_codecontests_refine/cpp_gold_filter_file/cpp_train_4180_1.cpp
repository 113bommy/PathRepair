#include <bits/stdc++.h>
using namespace std;
int main() {
  string s;
  cin >> s;
  int n = s.length();
  vector<string> ret(3);
  cout << "? ";
  for (int i = 0; i < n; i++) {
    cout << (char)(i / 676 + 'a');
  }
  cout << endl;
  cin >> ret[0];
  cout << "? ";
  for (int i = 0; i < n; i++) {
    cout << (char)(i % 676 / 26 + 'a');
  }
  cout << endl;
  cin >> ret[1];
  cout << "? ";
  for (int i = 0; i < n; i++) {
    cout << (char)(i % 26 + 'a');
  }
  cout << endl;
  cin >> ret[2];
  string ans(n, 'a');
  for (int i = 0; i < n; i++) {
    int idx =
        (ret[0][i] - 'a') * 676 + (ret[1][i] - 'a') * 26 + (ret[2][i] - 'a');
    ans[idx] = s[i];
  }
  cout << "! " << ans << endl;
  return 0;
}
