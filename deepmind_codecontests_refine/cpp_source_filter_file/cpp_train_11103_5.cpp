#include <bits/stdc++.h>
using namespace std;
int main() {
  int x, n;
  char s[300];
  scanf("%d\n", &x);
  n = x;
  for (int i = 3; i <= n + 2; i++) {
    scanf("%c", &s[i]);
    while (s[i] != 'U' && s[i] != 'R') {
      i--;
      continue;
    }
    if ((s[i] = 'U' && s[i - 1] == 'R') || (s[i] == 'R' && s[i - 1] == 'U'))
      s[i] = 'D', x--;
  }
  cout << x << endl;
}
