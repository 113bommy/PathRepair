#include <bits/stdc++.h>
int n, i;
using namespace std;
int main() {
  cin >> n;
  for (int j = 0; j < n; j++) {
    cin >> i;
    if (i == 1) {
      cout << "HARD\n";
      return 0;
    }
    cout << "EASY\n";
    return 0;
  }
}
