#include <bits/stdc++.h>
using namespace std;
int main() {
  int x = 0;
  int t;
  char s[4];
  cin >> t;
  while (t--) {
    cin >> s;
    if (strcmp(s, "X++") == 0)
      x++;
    else if (strcmp(s, "++X") == 0)
      ++x;
    else if (strcmp(s, "--X") == 0)
      --x;
    else if (strcmp(s, "X--") == 0)
      x--;
  }
  cout << x;
}
