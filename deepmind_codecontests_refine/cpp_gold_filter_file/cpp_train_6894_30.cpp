#include <bits/stdc++.h>
using namespace std;
int main() {
  int T;
  cin >> T;
  while (T--) {
    int n, m;
    cin >> n >> m;
    if (n % m == 0)
      cout << "YES" << endl;
    else
      cout << "NO" << endl;
  }
}
