#include <bits/stdc++.h>
using namespace std;
int main() {
  long n, a = 0, b, c = 1;
  char d[2001], r[2001];
  cin >> n;
  cin >> d;
  b = n;
  for (int i = n; i >= 0; i--) {
    if (c % 2 == 1) {
      r[b] = d[i];
      b--;
    } else if (c % 2 == 0) {
      r[a] = d[i];
      a++;
    }
    c++;
  }
  a = 0;
  b = n - 1;
  for (int i = 0; i < n; i++) {
    d[a] = r[b];
    a++;
    b--;
  }
  cout << d;
  return 0;
}
