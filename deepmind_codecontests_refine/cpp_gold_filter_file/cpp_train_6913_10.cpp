#include <bits/stdc++.h>
using namespace std;
int main() {
  int k, d;
  cin >> k >> d;
  if (k > 1 && d == 0) return cout << "No solution" << endl, 0;
  cout << d;
  k--;
  while (k--) cout << 0;
  cout << endl;
  return 0;
}
