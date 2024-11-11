#include <bits/stdc++.h>
using namespace std;
int main() {
  int k, d, i, j;
  cin >> k >> d;
  if (d == 0 && k > 1)
    cout << "No solution\n";
  else {
    cout << d;
    for (i = 1; i < k; i++) cout << 0;
    cout << endl;
  }
  return 0;
}
