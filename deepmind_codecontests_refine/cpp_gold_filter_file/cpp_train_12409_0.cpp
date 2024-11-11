#include <bits/stdc++.h>
using namespace std;
int main() {
  int l, u = 0, r, leght = 0, num;
  int f[10] = {0, 0, 0, 0, 0, 0, 0, 0, 0, 0};
  cin >> l >> r;
  for (int i = l; i <= r; i++) {
    num = i;
    memset(f, 0, sizeof(int) * 10);
    while (num != 0) {
      f[num % 10]++;
      if (f[num % 10] > 1) goto a;
      num /= 10;
    }
    cout << i;
    goto b;
  a:
    continue;
  }
  cout << -1;
b:
  return 0;
}
