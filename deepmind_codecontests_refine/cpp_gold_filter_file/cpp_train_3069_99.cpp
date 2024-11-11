#include <bits/stdc++.h>
using namespace std;
int s[255];
int main() {
  s['Q'] = 9;
  s['q'] = -9;
  s['R'] = 5;
  s['r'] = -5;
  s['B'] = 3;
  s['b'] = -3;
  s['N'] = 3;
  s['n'] = -3;
  s['P'] = 1;
  s['p'] = -1;
  string inp;
  int sum = 0;
  for (int i = 0; i < 8; ++i) {
    getline(cin, inp);
    for (int j = 0; j < 8; ++j) {
      sum += s[inp[j]];
    }
  }
  (sum == 0) ? (cout << "Draw") : cout << (sum > 0 ? "White" : "Black");
}
