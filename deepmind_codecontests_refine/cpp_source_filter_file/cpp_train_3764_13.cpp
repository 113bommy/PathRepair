#include <bits/stdc++.h>
using namespace std;
int main() {
  int n = 4;
  int a[4];
  for (int i = 0; i < 4; i++) {
    cin >> a[i];
  }
  sort(a, a + n);
  for (int i = 0; i < 3; i++) {
    cout << a[4] - a[i] << " ";
  }
}
