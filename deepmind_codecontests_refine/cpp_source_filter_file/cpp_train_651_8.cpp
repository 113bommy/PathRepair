#include <bits/stdc++.h>
using namespace std;
int main() {
  int t;
  cin >> t;
  while (t--) {
    int n;
    cin >> n;
    int x = 0;
    for (int i = 0; i < n; i++) {
      x += 2;
      cout << x << " ";
    }
    cout << endl;
  }
}
