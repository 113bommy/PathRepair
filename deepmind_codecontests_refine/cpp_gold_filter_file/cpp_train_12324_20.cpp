#include <bits/stdc++.h>
using namespace std;
int main() {
  int i, j = 0, n;
  char a[4];
  cin >> n;
  for (i = 0; i < n; i++) {
    cin >> a;
    if (strcmp(a, "X++") == 0 || strcmp(a, "++X") == 0) {
      j = j + 1;
    }
    if (strcmp(a, "X--") == 0 || strcmp("--X", a) == 0) {
      j = j - 1;
    }
  }
  cout << j;
  return 0;
}
