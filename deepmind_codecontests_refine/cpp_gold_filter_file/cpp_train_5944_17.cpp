#include <bits/stdc++.h>
using namespace std;
int main() {
  long long i, n, x, d = 0;
  cin >> n;
  for (i = 0; i < n; i++) {
    cin >> x;
    if (x % 2 == 0)
      d = x - 1;
    else
      d = x;
    cout << d << " ";
  }
}
