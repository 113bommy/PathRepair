#include <bits/stdc++.h>
using namespace std;
int newGame() {
  string s;
  cin >> s;
  if (s == "start") return 1;
  return 0;
}
int ask(long long x, long long y) {
  cout << "? " << x << ' ' << y << endl;
  string s;
  cin >> s;
  if (s == "e") return 0;
  if (s == "x") return 1;
  return -1;
}
int main() {
  while (newGame()) {
    if (ask(0, 1) == 1) {
      cout << "! " << 1 << endl;
      continue;
    }
    long long l = 1, r = 2, mid;
    for (;;) {
      int ans = ask(l, r);
      if (ans == 1) break;
      l <<= 1, r <<= 1;
    }
    int k = l;
    l++;
    while (l <= r) {
      mid = (l + r) / 2;
      int ans = ask(mid, k);
      if (ans == 1)
        l = mid + 1;
      else
        r = mid - 1;
    }
    cout << "! " << l << endl;
  }
  return 0;
}
