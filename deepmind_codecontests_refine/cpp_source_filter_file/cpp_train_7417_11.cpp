#include <bits/stdc++.h>
using namespace std;
int main() {
  int n, i, j;
  cin >> n;
  std::string a, b;
  for (i = 0; i < n; i++) {
    cin >> a;
    b += a[0];
    for (j = 1; j < a.length(); j += 2) {
      b += a[j];
    }
    cout << b;
    b = "";
  }
}
