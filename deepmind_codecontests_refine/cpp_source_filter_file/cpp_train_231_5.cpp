#include <bits/stdc++.h>
using namespace std;
int main() {
  long long int q;
  cin >> q;
  while (q--) {
    long long int n, k = 0, i;
    cin >> n;
    for (i = n; i > 6;) {
      if (i % 6 == 0) {
        i = i / 6;
        k++;
      } else {
        i = i * 2;
        k++;
      }
    }
    if (i == 1) {
      cout << k << endl;
    } else if (i == 3) {
      cout << k + 2 << endl;
    } else {
      cout << "-1" << endl;
    }
  }
}
