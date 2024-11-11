#include <bits/stdc++.h>
using namespace std;
int main() {
  string s;
  int n, cntx = 1, cnty = 1;
  scanf("%d", &n);
  while (n--) {
    cin >> s;
    if (s == "ULDR")
      cntx++, cnty++;
    else if (s == "UR")
      cntx++;
    else if (s == "DL")
      cnty++;
    else
      cnty++;
  }
  cout << 1LL * cntx * cnty << endl;
}
