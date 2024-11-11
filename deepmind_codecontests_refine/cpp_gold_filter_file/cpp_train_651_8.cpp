#include <bits/stdc++.h>
using namespace std;
int main() {
  int t;
  cin >> t;
  while (t--) {
    int n;
    cin >> n;
    int x = n * 4;
    for (int i = 1; i <= n; i++) {
      x -= 2;
      cout << x << " ";
    }
    cout << endl;
  }
}
