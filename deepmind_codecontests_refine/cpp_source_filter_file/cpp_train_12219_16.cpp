#include <bits/stdc++.h>
using namespace std;
int main() {
  int n, m(0), a(0), b(0), c(0), x;
  cin >> n;
  for (int i = 0; i < n; i++) {
    cin >> x;
    if (x % 3 == 1)
      a += x;
    else if (x % 3 == 2)
      b += x;
    else
      c += x;
  }
  m = max(max(a, b), c);
  if (m == a)
    cout << "chest";
  else if (m == b)
    cout << "biceps";
  else
    cout << "back";
}
