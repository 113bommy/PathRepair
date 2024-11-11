#include <bits/stdc++.h>
using namespace std;
char og[101];
int main() {
  int i, j, k = -1, l, c;
  cin >> l;
  cin >> og;
  for (i = 0; i <= l; i++) {
    if (k == -1) {
      if (og[i] == 'o') {
        k = i;
        c = 1;
      } else if (og[i])
        cout << og[i];
    } else {
      if ((og[i] == 'g' && c & 1) || (og[i] == 'o' && (c & 1) == 0)) {
        c++;
      } else {
        if (c < 3) {
          for (int x = k; x <= i; x++) cout << og[x];
          i--;
        } else if (c & 1) {
          cout << "***";
          i--;
        } else {
          cout << "***" << og[i - 1];
          i--;
        }
        k = -1;
      }
    }
  }
}
