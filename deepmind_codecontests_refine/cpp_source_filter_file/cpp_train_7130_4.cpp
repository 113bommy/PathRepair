#include <bits/stdc++.h>
using namespace std;
int main() {
  int n;
  cin >> n;
  int count = 0;
  for (int i = 0; i < n; i++) {
    string s;
    cin >> s;
    if ((s.size() == 1 && s[0] >= '1' && s[0] <= '9') ||
        (s.size() == 2 && s[0] == '1' && s[1] < '8'))
      count++;
    if (s == "ABSINTH" || s == "BEER" || s == "BRANDY" || s == "CHAMPAGNE" ||
        s == "GIN" || s == "RUM" || s == "SAKE" || s == "TEQUILA" ||
        s == "VODKA" || s == "WHISKEY" || s == "WINE")
      count++;
  }
  cout << count << endl;
}
