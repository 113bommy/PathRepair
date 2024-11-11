#include <bits/stdc++.h>
using namespace std;
int main() {
  int t;
  cin >> t;
  while (t--) {
    float n, m;
    cin >> n >> m;
    if (n == m * 2)
      cout << "YES" << endl;
    else
      cout << "NO" << endl;
  }
  return 0;
}
