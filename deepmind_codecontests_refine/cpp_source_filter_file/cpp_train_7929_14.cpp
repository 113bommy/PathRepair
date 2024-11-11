#include <bits/stdc++.h>
using namespace std;
int main() {
  int x, y, a[100000], b[100000];
  cin >> x;
  for (int i = 0; i < x; i++) {
    cin >> a[i];
  }
  sort(a, a + x);
  cin >> y;
  for (int i = 0; i < y; i++) {
    cin >> b[i];
  }
  sort(b, b + x);
  cout << a[x - 1] << " " << b[x - 1];
}
