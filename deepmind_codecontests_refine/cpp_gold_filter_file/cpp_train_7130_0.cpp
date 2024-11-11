#include <bits/stdc++.h>
using namespace std;
set<string> S;
void make() {
  S.insert("ABSINTH");
  S.insert("BEER");
  S.insert("BRANDY");
  S.insert("CHAMPAGNE");
  S.insert("GIN");
  S.insert("RUM");
  S.insert("SAKE");
  S.insert("TEQUILA");
  S.insert("VODKA");
  S.insert("WHISKEY");
  S.insert("WINE");
}
bool isNUM(string x) {
  if (isdigit(x[x.size() - 1]))
    return true;
  else
    return false;
}
int main() {
  make();
  bool sw = false;
  string ss;
  int n, years, ans = 0;
  cin >> n;
  while (n--) {
    cin >> ss;
    if (isNUM(ss)) {
      years = atoi(ss.data());
      if (years < 18) ans++;
    } else {
      if (S.count(ss)) ans++;
    }
  }
  cout << ans;
  return 0;
}
