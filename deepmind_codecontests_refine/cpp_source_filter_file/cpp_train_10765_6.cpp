#include <bits/stdc++.h>
using namespace std;
void solve(int n) {
  if (n == 0) {
    cout << "O-|-OOOO";
  }
  if (n == 1) {
    cout << "O-|O-OOO";
  }
  if (n == 2) {
    cout << "O-|OO-OO";
  }
  if (n == 3) {
    cout << "O-|OOO-O";
  }
  if (n == 4) {
    cout << "O-|OOOO-";
  }
  if (n == 5) {
    cout << "-O|-OOOO";
  }
  if (n == 6) {
    cout << "-O|O-OOO";
  }
  if (n == 7) {
    cout << "-O|OO-OO";
  }
  if (n == 8) {
    cout << "-O|-OOO-O";
  }
  if (n == 9) {
    cout << "-O|OOOO-";
  }
  cout << endl;
}
int main() {
  int n;
  cin >> n;
  if (n == 0) {
    solve(n);
    return 0;
  }
  while (n != 0) {
    solve(n % 10);
    n = n / 10;
  }
  return 0;
}
