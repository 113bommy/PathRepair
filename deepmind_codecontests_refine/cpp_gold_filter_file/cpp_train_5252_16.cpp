#include <bits/stdc++.h>
using namespace std;
int main() {
  long long x, n, c = 0, c1 = 0, c2 = 0;
  cin >> n;
  for (int i = 0; i < n; i++) {
    cin >> x;
    if (x % 3 == 0)
      c++;
    else if (x % 3 == 1)
      c1++;
    else if (x % 3 == 2)
      c2++;
  }
  cout << c / 2 + min(c1, c2);
}
