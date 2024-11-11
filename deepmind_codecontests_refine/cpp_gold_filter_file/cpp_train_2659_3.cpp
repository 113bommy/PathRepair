#include <bits/stdc++.h>
using namespace std;
int main() {
  int x, y, q = 0;
  cin >> x >> y;
  int s[x];
  for (int i = 0; i < x; i++) {
    cin >> s[i];
  }
  for (int j = 0; j < x; j++) {
    if (s[j] > y) {
      q += 2;
    } else if (s[j] <= y) {
      q++;
    }
  }
  cout << q;
  return 0;
}
