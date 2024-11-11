#include <bits/stdc++.h>
using namespace std;
int main() {
  short int n;
  cin >> n;
  vector<int> t(100);
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
  for (short int i = 0; i < 100; i++) {
    if (t[i] == n) cout << i << " ";
  }
  return 0;
}
