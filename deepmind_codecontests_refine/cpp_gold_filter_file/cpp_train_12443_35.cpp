#include <bits/stdc++.h>
using namespace std;
int64_t s, x, mask20 = (1 << 20) - 1, waysCarry = 0, waysNoCarry = 0, total = 0;
int main() {
  cin >> s >> x;
  int first20s = s & mask20, first20x = x & mask20;
  for (int i = 0; i < (1 << 20); i++) {
    int t = first20x ^ i;
    if (i + t == first20s)
      waysNoCarry++;
    else if (((i + t) & mask20) == first20s)
      waysCarry++;
  }
  int last20s = (s >> 20), last20x = (x >> 20);
  for (int i = 0; i < (1 << 22); i++) {
    int t = last20x ^ i;
    if (t + i == last20s)
      total += waysNoCarry;
    else if (t + i == last20s - 1)
      total += waysCarry;
  }
  if (x == s) total -= 2;
  cout << total << "\n";
  return 0;
}
