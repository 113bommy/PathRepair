#include <bits/stdc++.h>
using namespace std;
const int INF = 2000000000;
char c[15][15] = {"ABSINTH", "BEER",    "BRANDY", "CHAMPAGNE", "GIN", "RUM",
                  "SAKE",    "TEQUILA", "VODKA",  "WHISKEY",   "WINE"};
int main() {
  int n, s = 0, t, flag;
  char a[110];
  cin >> n;
  for (int i = 0; i < n; i++) {
    cin >> a;
    if (a[0] >= 65) {
      flag = 0;
      for (int j = 0; j < 11; j++) {
        if (strcmp(c[j], a) == 0) flag = 1;
      }
      if (flag) s++;
      continue;
    }
    t = atoi(a);
    if (t < 18) s++;
  }
  cout << s;
  return 0;
}
