#include <bits/stdc++.h>
using namespace std;
int sqrCount(int n) {
  if (n == 1) return 1;
  return 4 * (n - 1) + sqrCount(n - 1);
}
int main() {
  int n;
  cin >> n;
  cout << sqrCount(n) << "\n";
}
