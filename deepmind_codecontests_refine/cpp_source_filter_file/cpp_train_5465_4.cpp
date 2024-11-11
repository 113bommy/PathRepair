#include <bits/stdc++.h>
using namespace std;
int main() {
  int times = 1;
  int T, S, q;
  int now = 0;
  int clk = 0;
  cin >> T >> S >> q;
  while (S <= T) {
    clk++;
    clk %= q;
    if (clk != 0) {
      S++;
    }
    now++;
    if (now > S && S != T) {
      now = 0;
      times++;
    }
  }
  cout << times << endl;
  return 0;
}
