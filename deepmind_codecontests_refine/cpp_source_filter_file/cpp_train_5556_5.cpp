#include <bits/stdc++.h>
using namespace std;
char s[305];
int main() {
  scanf("%s", s);
  int n = strlen(s);
  int pos = 0, maxp = -10000, minp = 10000;
  for (int i = 0; i < n; i++) {
    if (s[i] == '+')
      pos++;
    else
      pos--;
    maxp = max(maxp, pos);
    minp = min(minp, pos);
  }
  cout << maxp - minp << endl;
  return 0;
}
