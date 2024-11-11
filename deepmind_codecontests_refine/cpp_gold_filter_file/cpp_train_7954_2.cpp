#include <bits/stdc++.h>
using namespace std;
char a[1000005];
int main() {
  scanf("%s", a);
  int l = strlen(a);
  int n;
  for (int i = 0; i < l; i++) {
    if (a[i] == '^') {
      n = i;
      break;
    }
  }
  long long c = 0, b = 0;
  for (int i = 0; i < l; i++) {
    if (a[i] >= '0' && a[i] <= '9') {
      if (i < n) {
        c += (n - i) * (a[i] - '0');
      } else {
        b += (i - n) * (a[i] - '0');
      }
    }
  }
  if (c > b)
    cout << "left" << endl;
  else if (b > c)
    cout << "right" << endl;
  else
    cout << "balance" << endl;
  return 0;
}
