#include <bits/stdc++.h>
using namespace std;
int ver(char a, char b) {
  int d;
  if (max(a, b) - min(a, b) == 32) return 1;
  if (a == b) return 1;
  if (a == '0' and b == 'O') return 1;
  if (a == '0' and b == 'o') return 1;
  if (b == '0' and a == 'o') return 1;
  if (a == 'O' and b == '0') return 1;
  if (a == '1' and b == 'l') return 1;
  if (a == '1' and b == 'I') return 1;
  if (b == '1' and a == 'I') return 1;
  if (b == '1' and a == 'l') return 1;
  if (a == '1' and b == 'L') return 1;
  if (a == '1' and b == 'i') return 1;
  if (b == '1' and a == 'L') return 1;
  if (b == '1' and a == 'i') return 1;
  if (a == 'i' || a == 'l') {
    d = a - 32;
    a = d;
  }
  if (b == 'i' || b == 'l') {
    d = b - 32;
    b = d;
  }
  if (a == 'I' and b == 'L') return 1;
  if (b == 'I' and a == 'L') return 1;
  return 0;
}
int l1, n, l, j, i, a, a2, a3;
int main() {
  string c, c1;
  l1 = 0;
  cin >> c;
  cin >> n;
  for (i = 1; i <= n; i++) {
    cin >> c1;
    l = 0;
    if (c.size() == c1.size()) {
      a = c.size() - 1;
      for (j = 0; j <= a; j++) {
        if (ver(c[j], c1[j]) == 0) {
          l = 1;
        }
      }
      if (l == 0) l1 = 1;
    }
  }
  if (l1 == 1) {
    cout << "No";
  } else
    cout << "Yes";
  return 0;
}
