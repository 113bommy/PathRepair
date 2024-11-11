#include <bits/stdc++.h>
using namespace std;
bool ok(int x) {
  bool f[10];
  memset(f, 1, sizeof(f));
  while (x > 0) {
    int y = x % 10;
    x /= 10;
    if (f[y] == 1)
      f[y] = 0;
    else
      return 0;
  }
  return 1;
}
int main() {
  int n;
  cin >> n;
  for (int i = n + 1; i <= 20000; i++)
    if (ok(i)) {
      cout << i;
      return 0;
    };
}
