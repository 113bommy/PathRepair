#include <bits/stdc++.h>
using namespace std;
int main() {
  long int n, i, x = 0;
  cin >> n;
  for (i = 1; i <= 40; i++) {
    x += i * (i + 1) / 2;
    if (x == n || x > n) break;
  }
  if (x == n)
    cout << i;
  else if (x > n)
    cout << i - 1;
  return 0;
}
