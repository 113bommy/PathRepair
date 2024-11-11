#include <bits/stdc++.h>
using namespace std;
long A[2000];
int n, t, x = 0, h, l, d;
int main() {
  cin >> d;
  cin >> n;
  for (l = 0; l < n; l++) {
    cin >> A[l];
    x = x + d - A[l];
  }
  x = x - A[n - 1];
  cout << x;
  return 0;
}
