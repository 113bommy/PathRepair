#include <bits/stdc++.h>
using namespace std;
int n, a, b, x, i;
int main() {
  cin >> n >> a;
  while (i < n - 1) {
    cin >> b;
    a += b;
    i++;
  }
  if (a % n == 0)
    cout << n;
  else
    cout << n - 1;
}
