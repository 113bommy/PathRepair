#include <bits/stdc++.h>
using namespace std;
int v[] = {1, 0, 0, 0, 1, 0, 1, 0, 2, 1, 1, 2, 0, 1, 0};
int main() {
  int a, s = 0;
  cin >> a;
  if (a == 0) {
    cout << 1;
    return 0;
  }
  while (a > 0) {
    s = s + v[a % 16];
    a = a / 16;
  }
  cout << s;
  return 0;
}
