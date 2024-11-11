#include <bits/stdc++.h>
using namespace std;
int main() {
  int fixed[10];
  int flipped[10];
  memset(fixed, -1, sizeof fixed);
  memset(flipped, 0, sizeof flipped);
  int n;
  cin >> n;
  for (int i = 0; i < n; i++) {
    char c;
    int tmp;
    cin >> c >> tmp;
    if (c == '|') {
      for (int i = 0; i < 10; i++)
        if (tmp & (1 << i)) fixed[i] = 1;
    } else if (c == '&') {
      for (int i = 0; i < 10; i++)
        if (!(tmp & (1 << i))) fixed[i] = 0;
    } else {
      for (int i = 0; i < 10; i++)
        if (tmp & (1 << i)) {
          if (fixed[i] != -1)
            fixed[i] ^= 1;
          else
            flipped[i] ^= 1;
        }
    }
  }
  int and_mask = 0, or_mask = 0, xor_mask = 0;
  for (int i = 0; i < 10; i++)
    if (fixed[i] == 0)
      and_mask |= 1 << i;
    else if (fixed[i] == 1)
      or_mask |= 1 << i;
    else if (flipped[i] == 1)
      xor_mask |= 1 << i;
  cout << 3 << endl;
  cout << "& " << and_mask << endl;
  cout << "| " << or_mask << endl;
  cout << "^ " << xor_mask << endl;
}
