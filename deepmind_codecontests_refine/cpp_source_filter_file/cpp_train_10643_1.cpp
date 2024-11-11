#include <bits/stdc++.h>
using namespace std;
int reverse(int n) {
  int s = 128, r = 0, d = 0, k = 0, co[10];
  while (n != 0) {
    d = n % 2;
    if (d == 1) r += s;
    s /= 2;
    n /= 2;
  }
  return r;
}
int main() {
  int p = 0, k = 0;
  char s[150], c;
  while ((c = getchar()) > 32 && c < 126) {
    s[k++] = c;
  }
  s[k] = '/0';
  int m = reverse(s[0]);
  cout << 256 - m << endl;
  for (int i = 1; i < k; i++) {
    int x1 = reverse(s[i]);
    if ((m - x1) >= 0) {
      p = m - x1;
    } else {
      p = 256 + m - x1;
    }
    cout << p << endl;
    m = x1;
  }
}
