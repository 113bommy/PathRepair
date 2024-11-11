#include <bits/stdc++.h>
using namespace std;
int main() {
  int n, k, t = 0;
  cin >> n;
  for (int i = 0; i < n; i++) {
    cin >> k;
    if (k == 1) {
      t = 1;
    }
  }
  if (k == 1) {
    cout << "HARD";
  } else {
    cout << "EASY";
  }
  return 0;
}
