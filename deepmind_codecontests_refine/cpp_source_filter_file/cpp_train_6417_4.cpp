#include <bits/stdc++.h>
using namespace std;
long long int fun(long long int n) {
  long long int y = 0;
  while (n) {
    y = y + n % 10;
    n = n / 10;
  }
  if (y % 10 == 0)
    return (1);
  else
    return 0;
}
int main() {
  long long int n;
  cin >> n;
  long long int p = 0;
  for (long long int i = 19;; i = i++) {
    if (fun(i)) p++;
    if (p == n) {
      cout << i;
      return 0;
    }
  }
  return 0;
}
