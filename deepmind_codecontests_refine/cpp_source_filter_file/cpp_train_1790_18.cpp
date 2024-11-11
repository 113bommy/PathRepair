#include <bits/stdc++.h>
using namespace std;
int solve(int n) {
  if (n % 4 == 0)
    return 0;
  else if (n % 4 == 2)
    return 2;
  else
    return 1;
}
int main() {
  int t;
  cin >> t;
  int n;
  while (t--) {
    cin >> n;
    cout << solve(n);
    cout << endl;
  }
  return 0;
}
