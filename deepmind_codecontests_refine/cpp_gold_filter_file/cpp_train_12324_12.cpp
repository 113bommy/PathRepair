#include <bits/stdc++.h>
using namespace std;
int main() {
  string operation;
  int n, X = 0;
  cin >> n;
  for (int i = 0; i < n; i++) {
    cin >> operation;
    if (operation == "++X" || operation == "X++") X++;
    if (operation == "--X" || operation == "X--") X--;
  }
  cout << X << endl;
  return 0;
}
