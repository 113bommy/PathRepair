#include <bits/stdc++.h>
using namespace std;
int main() {
  int n;
  cin >> n;
  for (int j = 1; j <= n; j++) {
    if (((j * (j + 1)) / 2) == n) {
      cout << "Yes\n";
      return 0;
    }
  }
  cout << "No\n" << endl;
}
