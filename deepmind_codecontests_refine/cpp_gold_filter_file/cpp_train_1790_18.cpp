#include <bits/stdc++.h>
using namespace std;
int solve(int n) {
  if (n == 2)
    return 2;
  else if (n % 2 == 0)
    return 0;
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
