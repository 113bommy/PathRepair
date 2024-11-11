#include <bits/stdc++.h>
using namespace std;
using Int = long long;
constexpr static int mod = 1e9 + 7;
constexpr static int inf = (1 << 30) - 1;
constexpr static Int infll = (1LL << 61) - 1;
#pragma GCC target("avx2")
#pragma GCC optimize("O3")
#pragma GCC optimize("unroll-loops")
string ask(Int p, Int q) {
  cout << '?' << ' ' << p << ' ' << q << endl;
  string s;
  cin >> s;
  return s;
}
string ans(Int a) {
  cout << '!' << ' ' << a << endl;
  string s;
  cin >> s;
  return s;
}
int main() {
  string cmd;
  cin >> cmd;
  while (1) {
    if (cmd != "start") return 0;
    Int k = 2;
    cmd = ask(0, 1);
    if (cmd == "x") {
      cmd = ans(1);
    }
    if (cmd == "start") continue;
    Int left = 2;
    while (left <= 1e9) {
      cmd = ask(left, 2 * left);
      if (cmd == "x") break;
      if (cmd == "end" or cmd == "e") return 0;
      left *= 2;
    }
    Int right = min(2 * left - 1, (Int)2e9);
    while (right - left > 1) {
      Int mid = (left + right) / 2;
      cmd = ask(left, mid);
      if (cmd == "end" or cmd == "e") return 0;
      if (cmd == "x") {
        right = mid;
      } else {
        left = mid;
      }
    }
    cmd = ans(right);
    if (cmd == "end" or cmd == "e") return 0;
  }
}
