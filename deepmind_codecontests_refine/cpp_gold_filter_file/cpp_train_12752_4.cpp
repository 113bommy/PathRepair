#include <bits/stdc++.h>
using namespace std;
char a;
int n, res;
string s[1001];
int main() {
  while (cin >> a) {
    if (a == '.') {
      for (int i = 0; i < n; i++)
        if (s[i] == s[n]) res = res + 1;
      s[n] = "";
      n--;
    } else {
      if (a == ':')
        n = n + 1;
      else {
        if (a == ',')
          n++;
        else
          s[n] += a;
      }
    }
  }
  cout << res << endl;
  return 0;
}
