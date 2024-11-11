#include <bits/stdc++.h>
using namespace std;
using ll = long long;
bool canWin(ll a, ll b) {
  if (a > b) {
    return 1;
  }
  if (b % 2 == 0) {
    if (a * 4 > b) {
      if (a * 2 > b) {
        return b % 2 != a % 2;
      } else {
        return 1;
      }
    } else {
      return canWin(a, b / 4);
    }
  } else {
    return b % 2 != a % 2;
  }
}
bool canLose(ll a, ll b) {
  if (a > b) {
    return 0;
  }
  return canWin(a, 2 * b);
}
ll t, a, b;
bool rez[2];
int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  cin >> t;
  rez[1] = 1;
  while (t--) {
    cin >> a >> b;
    bool newRez[2] = {0, 0};
    if ((canWin(a, b) && rez[1]) ||
        (canWin(a + 1, b) && canWin(a * 2, b) && rez[0]) ||
        (canWin(a, b) && canWin(a + 1, b) && canWin(a * 2, b))) {
      newRez[1] = 1;
    }
    if ((canLose(a, b) && rez[1]) ||
        (canLose(a + 1, b) && canLose(a * 2, b) && rez[0]) ||
        (canLose(a, b) && canLose(a + 1, b) && canLose(a * 2, b))) {
      newRez[0] = 1;
    }
    rez[0] = newRez[0];
    rez[1] = newRez[1];
  }
  cout << rez[0] << " " << rez[1] << "\n";
}
