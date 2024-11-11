#include <bits/stdc++.h>
using namespace std;
int main() {
  int a[1000], b, c;
  for (int i = 0; i < 2; ++i) {
    cin >> a[i];
  }
  cin >> c;
  for (int i = 2; i < 20; ++i) {
    a[i] = a[i - 1] + a[i - 2];
  }
  for (int i = 0; i < 20; ++i) {
    if (i == c) {
      cout << a[i];
      return 0;
    }
  }
}
