#include <bits/stdc++.h>
using namespace std;
int main() {
  int t, n, r, i;
  cin >> t >> n;
  if (t == 10) {
    if (n == 1)
      cout << "-1";
    else {
      for (i = 0; i < n - 1; i++) cout << "1";
      cout << "0";
    }
    return 0;
  }
  for (i = 0; i < t; i++) cout << n;
  return 0;
}
