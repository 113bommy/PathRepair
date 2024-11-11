#include <bits/stdc++.h>
using namespace std;
int main() {
  int n, i, pay, h;
  cin >> n;
  pay = 0;
  for (i = 1; i <= n; i++) {
    cin >> h;
    if (h > pay) pay = h;
  }
  cout << pay << endl;
  return 0;
}
