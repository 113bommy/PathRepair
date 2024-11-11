#include <bits/stdc++.h>
using namespace std;
string s;
int n;
int cntt;
int cnth;
int poh[2200];
int pot[2200];
int ct;
int main() {
  cin >> n;
  cin >> s;
  cntt = 0;
  cnth = 0;
  for (int i = 0; i < n; i++) {
    if (s[i] == 'H') {
      cnth++;
    } else {
      cntt++;
    }
    poh[i] = cnth;
    pot[i] = cntt;
  }
  ct = cntt;
  for (int i = n; i < n * 2; i++) {
    if (s[i - n] == 'H') {
      cnth++;
    } else {
      cntt++;
    }
    poh[i] = cnth;
    pot[i] = cntt;
  }
  int ans = poh[ct - 1];
  for (int i = 1; i < n; i++) {
    if (poh[i + ct - 1] - poh[i - 1] < ans) {
      ans = poh[i + ct - 1] - poh[i - 1];
    }
  }
  cout << ans << endl;
  return 0;
}
