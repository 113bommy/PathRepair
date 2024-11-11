#include <bits/stdc++.h>
using namespace std;
int main() {
  int n, i, X = 0;
  string s;
  cin >> n;
  for (i = 0; i < n; i++) {
    cin >> s;
    if (s == ("X++") || s == ("++X")) {
      X++;
    } else if (s == ("--X") || s == ("X--")) {
      --X;
    }
  }
  cout << X;
  return 0;
}
