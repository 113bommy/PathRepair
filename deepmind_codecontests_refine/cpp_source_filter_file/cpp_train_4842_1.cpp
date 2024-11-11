#include <bits/stdc++.h>
using namespace std;
int n;
string s[110];
int v[110];
int main() {
  cin >> n;
  for (int i = 0; i < n; ++i) {
    cin >> s[i];
    for (int j = 0; j < s[i].length(); ++j) v[i] |= (1 << (s[i][j] - 'a'));
  }
  int ans = -1;
  for (int i = 0; i < 26; ++i)
    for (int j = i; j < 26; ++j) {
      int tans = 0, sta = (1 << i) | (1 << j);
      for (int k = 0; k < n; ++k)
        if ((v[k] & sta) && ((v[k] & (~sta)) == 0)) tans += s[k].length();
      if (tans != 0) ans = max(ans, tans);
    }
  cout << ans << endl;
  return 0;
}
