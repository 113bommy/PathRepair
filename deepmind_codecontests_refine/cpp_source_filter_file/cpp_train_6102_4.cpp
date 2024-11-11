#include <bits/stdc++.h>
using namespace std;
int main() {
  int n, f = 0;
  cin >> n;
  if (n & 1 == 0) f = 1;
  for (int i = 0; i < n; i++) {
    int x;
    cin >> x;
    if (i == 0 || i == n - 1) {
      if (x % 2 == 0) f = 1;
    }
  }
  if (f)
    cout << "No" << endl;
  else
    cout << "Yes" << endl;
}
