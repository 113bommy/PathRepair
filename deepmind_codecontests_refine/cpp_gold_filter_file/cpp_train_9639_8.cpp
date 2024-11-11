#include <bits/stdc++.h>
using namespace std;
int main() {
  int coins[3], ans = 0;
  cin >> coins[0] >> coins[1];
  int turn = 0;
  while (1) {
    int val = 220;
    if (turn == 0) {
      if (coins[0] >= 2) {
        val = 20;
        coins[0] -= 2;
      } else if (coins[0] == 1) {
        val = 120;
        coins[0]--;
      }
      int rest = val / 10;
      if (rest > coins[1]) {
        ans = turn;
        break;
      }
      coins[1] -= rest;
    } else {
      bool ys = false;
      for (int i = 0; i <= min(2, coins[0]); i++) {
        int p = (val - i * 100) / 10;
        if (p <= coins[1]) {
          ys = true;
          coins[0] -= i;
          coins[1] -= p;
          break;
        }
      }
      if (!ys) {
        ans = turn;
        break;
      }
    }
    turn ^= 1;
  }
  if (ans == 0)
    cout << "Hanako\n";
  else
    cout << "Ciel\n";
}
