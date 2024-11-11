#include <bits/stdc++.h>
using namespace std;
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  int zera = 0;
  int jeden = 0;
  int szesc = 0;
  int osiem = 0;
  int dziewiec = 0;
  string s;
  cin >> s;
  int mod = 0;
  for (auto &p : s) {
    int pp = p - '0';
    if (pp == 1 && !jeden)
      ++jeden;
    else if (pp == 6 && !szesc)
      ++szesc;
    else if (pp == 8 && !osiem)
      ++osiem;
    else if (pp == 9 && !dziewiec)
      ++dziewiec;
    else if (pp == 0)
      ++zera;
    else {
      mod *= 7;
      mod += pp;
      mod %= 7;
      cout << pp;
    }
  }
  vector<string> dop = {"1869", "6198", "1896", "9186", "9168", "6189", "8691"};
  cout << dop[mod];
  while (zera--) cout << 0;
  return 0;
}
