#include <bits/stdc++.h>
using namespace std;
int main(void) {
  ios_base::sync_with_stdio(false), cin.tie(0), cout.tie(0);
  srand(time(NULL));
  int t;
  cin >> t;
  while (t--) {
    string str, out;
    int cntr1, cnts1, cntp1, cntr2 = 0, cnts2 = 0, cntp2 = 0, n, ans = 0, i;
    cin >> n;
    cin >> cntr1 >> cntp1 >> cnts1;
    cin >> str;
    for (i = 0; i < n; i++) {
      if (str[i] == 'R')
        cntr2++;
      else if (str[i] == 'P')
        cntp2++;
      else if (str[i] == 'S')
        cnts2++;
      out += 'a';
    }
    ans = ans + min(cntr1, cnts2);
    ans += min(cnts1, cntp2);
    ans += min(cntp1, cntr2);
    if (ans >= ceil(n / 2.0)) {
      cout << "YES\n";
      for (i = 0; i < n; i++) {
        if (str[i] == 'R' && cntp1 > 0)
          out[i] = 'P', cntp1--;
        else if (str[i] == 'P' && cnts1 > 0)
          out[i] = 'S', cnts1--;
        else if (str[i] == 'S' && cntr1 > 0)
          out[i] = 'R', cntr1--;
      }
      for (i = 0; i < n; i++) {
        if (out[i] == 'a' && cntp1 > 0)
          out[i] = 'P', cntp1--;
        else if (out[i] == 'a' && cnts1 > 0)
          out[i] = 'S', cnts1--;
        else if (out[i] == 'a' && cntr1 > 0)
          out[i] = 'R', cntr1--;
      }
      cout << out << "\n";
    } else
      cout << "NO\n";
  }
}
