#include <bits/stdc++.h>
using namespace std;
int main() {
  int n, p, q, a, c = 1, b;
  cin >> n;
  cin >> a >> b;
  p = a;
  q = b;
  int num = n;
  n--;
  int max = 1;
  while (n--) {
    cin >> a >> b;
    if (p == a && q == b) {
      c++;
    } else if (c > 1) {
      if (max < c) max = c;
      c = 1;
    }
    p = a;
    q = b;
  }
  if (c > max) max = c;
  cout << max;
  return 0;
}
