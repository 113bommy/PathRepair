#include <bits/stdc++.h>
#pragma comment(linker, "/STACK:64000000")
using namespace std;
string a[11] = {"ABSINTH", "BEER",    "BRANDY", "CHAMPAGNE", "GIN", "RUM",
                "SAKE",    "TEQUILA", "VODKA",  "WHISKEY",   "WINE"};
string s;
int r = 0;
int pow(int aa, int bb) {
  if (bb == 0) return 1;
  int rr = 1;
  for (int i = 0; i < bb; i++) rr *= aa;
  return rr;
}
int main() {
  int n;
  cin >> n;
  for (int i = 0; i < n; i++) {
    cin >> s;
    if (isdigit(s[0])) {
      int w = 0;
      for (int j = 0; j < s.size(); j++)
        w += pow(10, s.size() - j - 1) * int(s[j] - '0');
      if (w > 18) r++;
    } else {
      for (int j = 0; j < 11; j++)
        if (s == a[j]) {
          r++;
        }
    }
  }
  cout << r;
  return 0;
}
