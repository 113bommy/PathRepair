#include <bits/stdc++.h>
using namespace std;
long long int qs(int a, int b) {
  long long int i = 1;
  for (a; a <= b; a++) {
    i *= a;
    i %= 1000000007;
  }
  return i;
}
int main() {
  int n, i, j, eve = 0;
  long long int a, b = 1, c = 2;
  cin >> n;
  for (i = 0; i < n; i++) {
    cin >> j;
    if (j % 2 == 1) {
      eve += 1;
    }
  }
  if (eve == 1) a = b;
  if (eve == 2) a = c;
  for (i = 3; i <= eve; i++) {
    a = (b + c * (i - 1)) % 1000000007;
    c = b;
    b = a;
  }
  cout << (a * qs(eve + 1, n)) % 1000000007 << endl;
  return 0;
}
