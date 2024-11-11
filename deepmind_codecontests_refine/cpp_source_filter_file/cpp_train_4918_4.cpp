#include <bits/stdc++.h>
using namespace std;
int main() {
  int t;
  cin >> t;
  while (t--) {
    int n, a, b;
    cin >> n >> a >> b;
    for (int i = 0; i < n; i++) {
      cout << (char)(97 + i % 26);
    }
    cout << endl;
  }
}
