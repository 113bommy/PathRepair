#include <bits/stdc++.h>
using namespace std;
int main() {
  int n, X = 0;
  string S;
  cin >> n;
  for (int k = 1; k <= n; k++) {
    cin >> S;
    if (S == "--X" || S == "X--")
      X--;
    else
      X++;
  }
  cout << X;
  return 0;
}
