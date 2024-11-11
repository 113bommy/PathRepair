#include <bits/stdc++.h>
using namespace std;
int n, a[2], b[2], i;
int main() {
  cin >> n;
  while (a[0] * a[1] < 2) {
    cin >> n;
    b[n % 2] = ++i;
    a[n % 2] += 1 - a[n % 2] / 4;
  }
  cout << b[a[0] - 1];
}
