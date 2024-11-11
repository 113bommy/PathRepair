#include <bits/stdc++.h>
const long double ACOSPI = (acosl(-1.0));
using namespace std;
int parents[100100];
int main() {
  ;
  ;
  cin.sync_with_stdio(0);
  string s;
  cin >> s;
  for (int i = 1; i < s.length() - 1; i++) {
    char huy[80];
    huy['A'] = huy['B'] = huy['C'] = 0;
    huy[s[i - 1]]++;
    huy[s[i]]++;
    huy[s[i + 1]]++;
    if (huy['A'] & huy['B'] & huy['C']) {
      cout << "Yes";
      goto FINALIZATION;
    }
  }
  cout << "No";
FINALIZATION:;
  ;
  return 0;
}
