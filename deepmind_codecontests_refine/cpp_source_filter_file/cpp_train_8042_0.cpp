#include <bits/stdc++.h>
using namespace std;
int main() {
  int t;
  cin >> t;
  while (t--) {
    int n;
    cin >> n;
    int x = (n * 4 - 4) / n;
    for (int i = 1; i <= x; i++) cout << "9";
    for (int i = 1; i <= n - x; i++) cout << "8";
    cout << endl;
    continue;
  }
  return 0;
}
