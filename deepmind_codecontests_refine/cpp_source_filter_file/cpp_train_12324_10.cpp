#include <bits/stdc++.h>
using namespace std;
int main() {
  string operation;
  int n, x = 0;
  cin >> n;
  for (int i = 0; i < n; i++) {
    cin >> operation;
    if (operation == "++x" || operation == "x++") x++;
    if (operation == "--x" || operation == "x--") x--;
  }
  cout << x << endl;
  return 0;
}
