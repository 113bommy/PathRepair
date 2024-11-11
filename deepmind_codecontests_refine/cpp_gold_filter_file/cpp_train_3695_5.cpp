#include <bits/stdc++.h>
using namespace std;
int main() {
  int m = 0, n = 0, k = 0;
  char ch;
  cin >> n;
  while (n--) {
    cin >> ch;
    if (ch == '0')
      m++;
    else
      k++;
  }
  cout << abs(m - k) << "\n";
  return 0;
}
