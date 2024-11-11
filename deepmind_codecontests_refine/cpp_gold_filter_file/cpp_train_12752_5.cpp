#include <bits/stdc++.h>
using namespace std;
const int N = 100000;
char a;
int n, ans;
string s[N];
int main() {
  while (cin >> a) {
    if (a == '.') {
      for (int i = 0; i < n; i++)
        if (s[i] == s[n]) ans++;
      s[n] = "", n--;
    } else if (a == ':' || a == ',')
      n++;
    else
      s[n] += a;
  }
  cout << ans << endl;
  return 0;
}
