#include <bits/stdc++.h>
using namespace std;
int n, m;
int main() {
  cin >> n >> m;
  if (n == 0) {
    cout << "Impossible\n";
    return 0;
  }
  cout << n + ((m - n) >= 0 ? (m - n) : 0) << " "
       << n + ((m - 1) >= 0 ? (m - 1) : 0) << '\n';
  return 0;
}
