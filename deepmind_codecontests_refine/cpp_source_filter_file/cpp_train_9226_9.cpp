#include <bits/stdc++.h>
using namespace std;
int main() {
  int n;
  int x[100];
  cin >> n;
  for (int i = 0; i < n; i++) {
    cin >> x[i];
  }
  for (int i = 0; i < 100; i++) {
    if (x[i] >= 3 && x[i] != 4 && x[i] != 5 && x[i] != 8 && x[i] != 11) {
      cout << "YES" << endl;
    } else {
      cout << "NO" << endl;
    }
  }
  return 0;
}
