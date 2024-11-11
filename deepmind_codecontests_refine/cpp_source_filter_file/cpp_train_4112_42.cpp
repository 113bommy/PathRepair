#include <bits/stdc++.h>
using namespace std;
int main() {
  int n, i, sum, nxt, digits;
  cin >> n;
  sum = 0;
  digits = 1;
  nxt = 1;
  i = 1;
  while (nxt <= n) {
    nxt = nxt * 10;
    sum += digits * (min(n, nxt) - i);
    i = nxt;
    digits++;
  }
  cout << sum + digits - 1 << endl;
  return 0;
}
