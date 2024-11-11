#include <bits/stdc++.h>
using namespace std;
signed main() {
  int t;
  cin >> t;
  for (int i = 0; i < t; i++) {
    string second;
    cin >> second;
    int maxi = second.find('R') + 1, q = 0, mai;
    for (int i = maxi + 1; i < second.size() && maxi != -1; i++) {
      if (second[i] == 'R') {
        maxi = max(q + 1, maxi);
        q = 0;
        mai = i;
      } else
        q++;
    }
    maxi = max(maxi, q + 1);
    if (second.find('R') == -1)
      cout << second.size() + 1 << endl;
    else
      cout << maxi << endl;
  }
  return 0;
}
