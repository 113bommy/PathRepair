#include <bits/stdc++.h>
using namespace std;
int main() {
  int n, x, a = 0, b = 0, c = 0, max1;
  cin >> n;
  for (int i = 0; i < n; i++) {
    cin >> x;
    if (x == 1)
      a++;
    else if (x == 2)
      b++;
    else
      c++;
  }
  max1 = max(a, b);
  max1 = max(max1, c);
  cout << n - max1 << endl;
  return 0;
}
