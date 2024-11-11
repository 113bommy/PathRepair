#include <bits/stdc++.h>
using namespace std;
int a, b, c, i, l, k;
int main() {
  cin >> a >> b >> c;
  for (i = 0; i <= c; i++) {
    for (l = 0; l <= c; l++) {
      if (a * i + b * i == c) {
        cout << "Yes";
        return 0;
      }
    }
  }
  cout << "No";
}
