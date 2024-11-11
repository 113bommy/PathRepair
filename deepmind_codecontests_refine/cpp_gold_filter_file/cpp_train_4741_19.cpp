#include <bits/stdc++.h>
using namespace std;
int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  int n;
  cin >> n;
  cout << 2 * (n / 3) + (n % 3 != 0) << "\n";
  return 0;
}
