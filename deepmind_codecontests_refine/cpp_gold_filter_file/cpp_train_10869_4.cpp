#include <bits/stdc++.h>
using namespace std;
int main() {
  int n, temp;
  cin >> n;
  int a[n];
  for (int i = 0; i < n; i++) {
    cin >> a[i];
  }
  int x = n, y = 1, min = abs(a[0] - a[n - 1]);
  for (int i = 0; i < n - 1; i++) {
    temp = a[i] - a[i + 1];
    if (abs(temp) < min) {
      x = i + 1;
      y = i + 2;
      min = abs(temp);
    }
  }
  cout << x << " " << y;
}
