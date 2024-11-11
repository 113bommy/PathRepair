#include <bits/stdc++.h>
using namespace std;
int main() {
  int n, sum = 0;
  cin >> n;
  string a[29] = {"0",       "1",       "2",      "3",          "4",   "5",
                  "6",       "7",       "8",      "9",          "10",  "11",
                  "12",      "13",      "14",     "15",         "16",  "17",
                  "ABSINTH", "BEER",    "BRANDY", "CHAMPAGNEC", "GIN", "RUM",
                  "SAKE",    "TEQUILA", "VODKA",  "WHISKEY",    "WINE"};
  while (n--) {
    string s;
    cin >> s;
    for (int i = 0; i < 29; i++) {
      if (s == a[i]) {
        sum++;
        break;
      }
    }
  }
  cout << sum << endl;
  return 0;
}
