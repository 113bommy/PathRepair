#include <bits/stdc++.h>
using namespace std;
int n, r, g, b, f1;
string s;
int main() {
  cin >> n >> s;
  for (int i = 0; i < n; i++)
    if (s[i] == 'B')
      b++;
    else if (s[i] == 'R')
      r++;
    else
      g++;
  if (b && !r && !g) return cout << 'B', 0;
  if (!b && r && !g) return cout << 'R', 0;
  if (!b && !r && g) return cout << 'G', 0;
  if (r > 1) f1++;
  if (g > 1) f1++;
  if (b > 1) f1++;
  if (f1 >= 2 || r && g && b) return cout << "BGR", 0;
  if (b == 1 && g == 1 && r == 0) return cout << 'R', 0;
  if (b == 0 && g == 1 && r == 1) return cout << 'B', 0;
  if (b == 1 && g == 0 && r == 1) return cout << 'G', 0;
  if (b == 1) {
    if (r)
      cout << "BG";
    else
      cout << "BR";
  } else if (g == 1) {
    if (b)
      cout << "GR";
    else
      cout << "BG";
  } else if (r == 1) {
    if (g)
      cout << "BR";
    else
      cout << "BG";
  }
}
