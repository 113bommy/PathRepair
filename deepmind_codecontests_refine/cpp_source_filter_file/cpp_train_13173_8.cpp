#include <bits/stdc++.h>
using namespace std;
int main() {
  int n, d;
  cin >> n;
  cin >> d;
  string t[d];
  for (int i = 0; i < d; i++) {
    cin >> t[i];
  }
  int m(0);
  int nb(0);
  for (int j = 0; j < d; j++) {
    unsigned int k(0);
    bool trouve(true);
    while (k < t[j].size() && trouve == true) {
      if (t[j][k] == '0') {
        trouve = false;
        nb++;
      }
      k++;
      if (nb > m) {
        m = nb;
      }
    }
    if (trouve == true) {
      nb = 0;
    }
  }
  cout << nb;
  return 0;
}
