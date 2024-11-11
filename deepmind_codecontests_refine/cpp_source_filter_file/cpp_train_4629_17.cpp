#include <bits/stdc++.h>
using namespace std;
int n, m;
bool was;
int main() {
  cin >> n;
  if (n < 4) {
    cout << "NO\n";
    return 0;
  }
  cout << "YES\n";
  while (n > 7) {
    if (was == true) cout << n << " + " << 0 << " = " << n << endl;
    cout << n << " - " << n - 1 << " = " << 1 << endl;
    cout << n - 3 << " + " << 1 << " = " << n - 2 << endl;
    cout << n - 2 << " - " << n - 2 << " = " << 0 << endl;
    n -= 4;
    was = true;
  }
  if (n == 4) {
    if (was == true) cout << n << " + " << 0 << " = " << n << endl;
    cout << 4 << " * " << 3 << " = " << 12 << endl;
    cout << 4 << " * " << 2 << " = " << 24 << endl;
    cout << 24 << " * " << 1 << " = " << 24 << endl;
  }
  if (n == 5) {
    if (was == true) cout << n << " + " << 0 << " = " << n << endl;
    cout << 5 << " * " << 3 << " = " << 15 << endl;
    cout << 4 << " * " << 2 << " = " << 8 << endl;
    cout << 15 << " + " << 8 << " = " << 23 << endl;
    cout << 23 << " + " << 1 << " = " << 24 << endl;
  }
  if (n == 6) {
    if (was == true) cout << n << " + " << 0 << " = " << n << endl;
    cout << 3 << " * " << 2 << " = " << 6 << endl;
    cout << 5 << " + " << 1 << " = " << 6 << endl;
    cout << 6 << " - " << 6 << " = " << 0 << endl;
    cout << 6 << " * " << 4 << " = " << 24 << endl;
    cout << 24 << " + " << 0 << " = " << 24 << endl;
  }
  if (n == 7) {
    if (was == true) cout << n << " + " << 0 << " = " << n << endl;
    cout << 1 << " + " << 7 << " = " << 8 << endl;
    cout << 3 << " + " << 6 << " = " << 9 << endl;
    cout << 4 << " + " << 5 << " = " << 9 << endl;
    cout << 9 << " + " << 9 << " = " << 18 << endl;
    cout << 18 << " + " << 8 << " = " << 26 << endl;
    cout << 26 << " - " << 2 << " = " << 24 << endl;
  }
  return 0;
}
