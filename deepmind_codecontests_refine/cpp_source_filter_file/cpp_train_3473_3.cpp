#include <bits/stdc++.h>
using namespace std;
int main() {
  int n, q, r, l;
  string s;
  cin >> n >> q >> s;
  while (q--) {
    int a[11] = {0};
    cin >> r >> l;
    r--, l--;
    string str = s.substr(r, l - r + 1);
    int CP = 0;
    bool DP = 0;
    while (CP >= 0 && CP < str.size()) {
      if (isdigit(str[CP])) {
        int x = str[CP] - '0';
        a[x]++;
        if (x == 0) {
          str.erase(str.begin() + CP);
          if (CP && !DP) CP--;
        } else
          --x, str[CP] = x + '0';
        if (!DP)
          CP++;
        else
          CP--;
      } else {
        if (str[CP] == '<')
          DP = 1;
        else
          DP = 0;
        int x = CP;
        if (!DP)
          CP++;
        else
          CP--;
        if (CP >= 0 && CP < str.size() && (str[CP] == '<' || str[CP] == '>')) {
          str.erase(str.begin() + x);
          if (!DP) CP--;
        }
      }
    }
    cout << a[0];
    for (int f = 1; f < 10; f++) cout << " " << a[f];
    cout << endl;
  }
  return 0;
}
