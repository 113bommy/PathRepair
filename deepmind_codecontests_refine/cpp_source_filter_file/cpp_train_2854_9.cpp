#include <bits/stdc++.h>
using namespace std;
int main() {
  int n, c = 2, c1;
  cin >> n;
  if (n == 1) {
    c1 = 1;
  } else
    c1 = 2;
  int a[n];
  for (int i = 0; i < n; i++) {
    cin >> a[i];
  }
  for (int i = 2; i < n; i++) {
    if (a[i] != (a[i - 1] + a[i - 2])) {
      c1 = std::max(c1, c);
      c = 0;
    } else {
      c = c + 1;
    }
    c1 = max(c, c1);
  }
  cout << c1;
}
