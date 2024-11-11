#include <bits/stdc++.h>
using namespace std;
int main() {
  int n, k, m;
  cin >> n;
  for (int i = 1; i <= n; i++) {
    cin >> k;
    if (k == 1) {
      m = 1;
    }
  }
  if (m == 1) {
    cout << "HARD";
  } else {
    cout << "EASY";
  }
  return 0;
}
