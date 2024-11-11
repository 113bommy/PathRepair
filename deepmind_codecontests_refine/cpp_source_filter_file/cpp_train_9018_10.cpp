#include <bits/stdc++.h>
using namespace std;
int main() {
  int a, b;
  cin >> a >> b;
  if (b >= a + 2 || b == 0 || b == a - 1) {
    cout << "no";
    return 0;
  }
  if (a % 2 == 1 && b % 2 == 0 || a % 2 == 0 && b % 2 == 1) {
    cout << "yes";
  } else
    cout << "no";
  return 0;
}
