#include <bits/stdc++.h>
using namespace std;
long int ff(long int n) { return (n * (n + 1)) / 2; }
int main() {
  long int n, i = 1, j = 65, sum = 0;
  cin >> n;
  if (n == 0) {
    cout << "AB";
    return 0;
  }
  while (n != 0) {
    i = 1;
    while (ff(i) <= n) {
      i++;
    }
    n -= ff(i - 1);
    while (i--) {
      printf("%c", j + 32);
    }
    j++;
  }
  return 0;
}
