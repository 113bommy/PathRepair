#include <bits/stdc++.h>
using namespace std;
int main() {
  long long n;
  int q;
  cin >> n >> q;
  for (int i = 0; i < q; i++) {
    long long temp;
    cin >> temp;
    string s;
    cin >> s;
    long long lev = 1, maxLev = 0, temp2 = 1;
    while (temp2 != (n + 1ll)) {
      maxLev++;
      temp2 *= 2ll;
    }
    while ((temp % (1ll << lev)) != (1ll << (lev - 1ll))) lev++;
    for (int j = 0; j < s.size(); j++) {
      if (s[j] == 'L') {
        if (lev > 1) {
          temp -= (1ll << (lev - 2ll));
          lev--;
        }
      } else if (s[j] == 'R') {
        if (lev > 1) {
          temp += (1ll << (lev - 2ll));
          lev--;
        }
      } else if (s[j] == 'U') {
        if (lev < maxLev) {
          long long temp1 = temp / (1ll << lev);
          if (temp1 % 2ll == 0)
            temp += (1ll << (lev - 1ll));
          else
            temp -= (1ll << (lev - 1ll));
          lev++;
        }
      }
    }
    cout << temp << endl;
  }
}
