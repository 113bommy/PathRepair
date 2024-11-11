#include <bits/stdc++.h>
using namespace std;
int main() {
  int a, b, n, x = 0, i;
  cin >> n >> a >> b;
  for (i = a + 1; i <= n; i++) {
    int k = n - (i);
    if (k <= b) x++;
  }
  cout << x;
}
