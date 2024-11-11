#include <bits/stdc++.h>
using namespace std;
int main() {
  int k;
  string arr[4];
  cin >> k;
  map<char, int> m;
  for (int i = 0; i < 4; ++i) cin >> arr[i];
  for (int i = 0; i < 4; i++) {
    for (int j = 0; j < 4; j++) {
      m[arr[i][j]]++;
    }
  }
  for (int i = 0; i <= 9; i++) {
    if (m[i + '0'] > 2 * k) {
      cout << "NO" << endl;
      return 0;
    }
  }
  cout << "YES" << endl;
}
