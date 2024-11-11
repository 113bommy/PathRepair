#include <bits/stdc++.h>
using namespace std;
int n, stare[100];
int main() {
  int i, j, x, bit;
  char c;
  cin >> n;
  for (i = 0; i < 20; ++i) stare[i] = 2;
  while (n--) {
    cin >> c >> x;
    if (c == '|') {
      for (bit = 0; bit < 20; ++bit)
        if ((1 << bit) & x) stare[bit] = 1;
    } else if (c == '^') {
      for (bit = 0; bit < 20; ++bit)
        if ((1 << bit) & x) {
          if (stare[bit] <= 1)
            stare[bit] ^= 1;
          else
            stare[bit] = 5 - stare[bit];
        }
    } else {
      for (bit = 0; bit < 20; ++bit)
        if (((1 << bit) & x) == 0) stare[bit] = 0;
    }
  }
  int val_or = 0;
  for (i = 0; i < 10; ++i)
    if (stare[i] == 1) val_or += (1 << i);
  int val_and = 0;
  for (i = 0; i < 10; ++i)
    if (stare[i]) val_and += (1 << i);
  int val_xor = 0;
  for (i = 0; i < 10; ++i)
    if (stare[i] == 3) val_xor += (1 << i);
  cout << "3\n";
  cout << "| " << val_or << "\n";
  cout << "& " << val_and << "\n";
  cout << "^ " << val_xor << "\n";
  return 0;
}
