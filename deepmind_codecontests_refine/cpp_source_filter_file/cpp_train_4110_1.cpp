#include <bits/stdc++.h>
using namespace std;
int form(int p, int t) { return max(3 * p / 10, p - p / 250 * 7); }
int win(int a, int b) {
  if (a == b) return 0;
  if (a > b)
    return 1;
  else
    return 2;
}
int main() {
  vector<string> output = {"Tie", "Misha", "Vasya"};
  int a, b, c, d;
  cin >> a >> b >> c >> d;
  cout << output[win(form(a, c), form(b, d))];
  return 0;
}
