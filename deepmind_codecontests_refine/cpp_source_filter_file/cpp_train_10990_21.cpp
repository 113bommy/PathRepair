#include <bits/stdc++.h>
using namespace std;
int main() {
  int n, d, col = 0;
  cin >> n >> d;
  if (n == 2)
    n = 29;
  else if (n == 4 || n == 6 || n == 9 || n == 11)
    n = 30;
  else
    n = 31;
  n -= (7 - d + 1);
  col = 1;
  col += (n / 7);
  n %= 7;
  if (n > 0) col++;
  cout << col << endl;
  return 0;
}
