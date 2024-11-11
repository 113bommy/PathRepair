#include <bits/stdc++.h>
using namespace std;
int main() {
  long long n = 0, k = 1, l, m;
  char c, d, f;
  scanf("%c", &c);
  while (scanf("%c", &d) != EOF && c != '\n') {
    if (c == d && k + 1 <= 5) {
      k++;
      continue;
    }
    if (c == d && k == 5) {
      n++;
      k = 1;
      continue;
    }
    if (c != d) {
      n++;
      k = 1;
      d = c;
    }
  }
  if (k > 0) n++;
  cout << n;
  return 0;
}
