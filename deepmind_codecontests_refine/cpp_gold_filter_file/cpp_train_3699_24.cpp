#include <bits/stdc++.h>
using namespace std;
int main() {
  ios ::sync_with_stdio(false);
  int n, r = 0, i, g = 0, b = 0;
  string s;
  cin >> n;
  cin >> s;
  for (i = 0; i < n; i++) {
    if (s[i] == 'R')
      r++;
    else if (s[i] == 'G')
      g++;
    else
      b++;
  }
  if (n == 1)
    cout << s;
  else {
    if (r >= 1 && g >= 1 && b >= 1)
      cout << "BGR\n";
    else if (r == n)
      cout << "R\n";
    else if (g == n)
      cout << "G\n";
    else if (b == n)
      cout << "B\n";
    else if (r > 1 && g > 1)
      cout << "BGR\n";
    else if (r > 1 && b > 1)
      cout << "BGR\n";
    else if (g > 1 && b > 1)
      cout << "BGR\n";
    else {
      if (r == 0) {
        if (n == 2)
          cout << "R\n";
        else if (g == 1)
          cout << "GR\n";
        else
          cout << "BR\n";
      } else if (g == 0) {
        if (n == 2)
          cout << "G\n";
        else if (b == 1)
          cout << "BG\n";
        else
          cout << "GR\n";
      } else if (b == 0) {
        if (n == 2)
          cout << "B\n";
        else if (r == 1)
          cout << "BR\n";
        else
          cout << "BG\n";
      }
    }
  }
  return 0;
}
