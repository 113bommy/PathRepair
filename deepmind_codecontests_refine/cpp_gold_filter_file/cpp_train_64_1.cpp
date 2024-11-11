#include <bits/stdc++.h>
using namespace std;
int main() {
  int n, a = 0, b = 0, tmp;
  cin >> n;
  for (int i = 0; i < n; i++) {
    cin >> tmp;
    if (tmp <= 1000000 / 2)
      a = tmp - 1;
    else {
      b = 1000000 - tmp;
      break;
    }
  }
  cout << max(a, b);
  return 0;
}
