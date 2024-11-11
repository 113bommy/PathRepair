#include <bits/stdc++.h>
using namespace std;
int main() {
  int t;
  cin >> t;
  while (t--) {
    int n, m;
    cin >> n;
    cin >> m;
    int flag = 0;
    if (n % m && m != 2) {
      cout << "YES" << endl;
    } else {
      cout << "NO" << endl;
    }
  }
}
