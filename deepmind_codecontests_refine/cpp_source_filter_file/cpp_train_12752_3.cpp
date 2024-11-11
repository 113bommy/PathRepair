#include <bits/stdc++.h>
using namespace std;
string S2;
int n, ans;
string s[600];
int main() {
  int i = 0;
  cin >> S2;
  while (i < S2.size()) {
    if (S2[i] == '.') {
      for (int i = n; i > 0; i--)
        if (s[i] == s[n]) ans++;
      s[n] = " ";
      n--;
    } else if (S2[i] == ':')
      n++;
    else if (S2[i] == ',')
      n++;
    else
      s[n] += S2[i];
    i++;
  }
  cout << ans << endl;
  return 0;
}
