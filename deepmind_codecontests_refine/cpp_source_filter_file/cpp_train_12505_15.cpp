#include <bits/stdc++.h>
using namespace std;
int main() {
  int x;
  int init = -1;
  scanf("%d", &x);
  if (x == 1) {
    printf("%d", init);
    return 0;
  }
  for (int i = x; i >= 1; i--) {
    for (int j = 1; j <= x; j++) {
      if (i % j == 0 && (i / j) < x) {
        cout << i << j << endl;
        return 0;
      }
    }
  }
  return 0;
}
