#include <bits/stdc++.h>
using namespace std;
int main() {
  int n, numberofgirl;
  cin >> n;
  if (n <= 2) {
    cout << -1 << endl;
  } else {
    for (int g = n; g >= 1; g--) {
      cout << g;
      if (g > n + 1) cout << " ";
    }
    cout << endl;
  }
  return 0;
}
