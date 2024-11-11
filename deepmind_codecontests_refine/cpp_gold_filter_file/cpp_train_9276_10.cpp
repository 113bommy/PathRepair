#include <bits/stdc++.h>
using namespace std;
int main() {
  short int n;
  cin >> n;
  vector<short int> t(101);
  short int y = n;
  while (y--) {
    short int x;
    cin >> x;
    for (short int i = 0; i < x; i++) {
      short int k;
      cin >> k;
      t[k]++;
    }
  }
  for (short int i = 0; i < 101; i++) {
    if (t[i] == n) cout << i << " ";
  }
  return 0;
}
