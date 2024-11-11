#include <bits/stdc++.h>
using namespace std;
int poz[6][6];
bool dp[1 << 20];
void place_init();
bool calc_dp(int mask);
int get_input();
int main() {
  place_init();
  for (int i(1); i < (1 << 20); i++) dp[i] = calc_dp(i);
  if (dp[get_input()])
    cout << "Karlsson\n";
  else
    cout << "Lillebror\n";
  return 0;
}
int get_input() {
  int mask(0);
  char c;
  for (int i(0); i < 19; i++) {
    cin >> c;
    while (c != '.' && c != 'O') cin >> c;
    if (c == 'O') mask |= 1 << i;
  }
  return mask;
}
bool calc_dp(int mask) {
  mask <<= 1;
  for (int i(1); i <= 5; i++) {
    for (int j(1); j <= 5; j++) {
      for (int q(0), m(mask); m & poz[i][j - q]; q++) {
        m ^= poz[i][j - q];
        if (!dp[m >> 1]) return true;
      }
      for (int q(0), m(mask); m & poz[i - q][j - q]; q++) {
        m ^= poz[i - q][j - q];
        if (!dp[m >> 1]) return true;
      }
      for (int q(0), m(mask); m & poz[i - q][j]; q++) {
        m ^= poz[i - q][j];
        if (!dp[m >> 1]) return true;
      }
    }
  }
  return false;
}
void place_init() {
  int i, cnt(0);
  for (i = 1; i <= 3; i++) {
    poz[1][i] = 1 << (++cnt);
  }
  for (i = 1; i <= 4; i++) {
    poz[2][i] = 1 << (++cnt);
  }
  for (i = 1; i <= 5; i++) {
    poz[3][i] = 1 << (++cnt);
  }
  for (i = 2; i <= 5; i++) {
    poz[4][i] = 1 << (++cnt);
  }
  for (i = 3; i <= 5; i++) {
    poz[5][i] = 1 << (++cnt);
  }
}
