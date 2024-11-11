#include <bits/stdc++.h>
using namespace std;
int main() {
  int t;
  cin >> t;
  while (t--) {
    int a, b, c;
    cin >> a >> b >> c;
    cout << max(1, b + c - a + 1) << " " << min(a, b + c - 1) << endl;
  }
}
