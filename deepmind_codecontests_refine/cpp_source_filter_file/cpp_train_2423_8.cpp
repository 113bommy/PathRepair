#include <bits/stdc++.h>
using namespace std;
int main() {
  int T;
  cin >> T;
  for (int x = 0; x < T; x++) {
    int n;
    cin >> n;
    for (int y = 1; y < n; y += 2) {
      int a, b;
      cin >> a >> b;
      cout << -b << " " << a;
    }
    cout << endl;
  }
}
