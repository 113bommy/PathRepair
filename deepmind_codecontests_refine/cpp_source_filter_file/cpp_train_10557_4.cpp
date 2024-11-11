#include <bits/stdc++.h>
using namespace std;
int main() {
  int x, y;
  cin >> x >> y;
  int a[x * 2];
  for (int i = 0; i < 2 * x; i++) {
    a[i] = i + 1;
  }
  for (int i = 1; i <= 2 * y; i++) {
    swap(a[i * 2], a[i * 2 - 1]);
  }
  for (int i = 0; i < x * 2; i++) {
    cout << a[i] << " ";
  }
  return 0;
}
