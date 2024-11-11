#include <bits/stdc++.h>
using namespace std;
int f(int hp, int atk, int def) {
  int ur = atk - def;
  if (ur <= 0) {
    return 1000000000;
  }
  return hp / ur + (hp % ur != 0);
}
int main() {
  int hpy, hpm, atkm, atky, defm, defy;
  cin >> hpy >> atky >> defy;
  cin >> hpm >> atkm >> defm;
  int zhp, zatk, zdef;
  cin >> zhp >> zatk >> zdef;
  int ans = 1000000000;
  for (int hpi = hpy; hpi <= 1000; hpi++) {
    for (int atki = atky; atki <= 200; atki++) {
      for (int defi = defy; defi <= 200; defi++) {
        if (f(hpm, atki, defm) < f(hpi, atkm, defi)) {
          if (ans >
              zhp * (hpi - hpy) + zatk * (atki - atky) + zdef * (defi - defy)) {
            ans =
                zhp * (hpi - hpy) + zatk * (atki - atky) + zdef * (defi - defy);
          }
        }
      }
    }
  }
  cout << ans;
  return 0;
}
