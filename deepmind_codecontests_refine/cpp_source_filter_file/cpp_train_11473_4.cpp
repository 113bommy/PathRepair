#include <bits/stdc++.h>
using namespace std;
int main() {
  int n;
  cin >> n;
  while (n-- > 0) {
    int a, b;
    cin >> a >> b;
    bool flag = false;
    for (int i = -b; i <= b; i++) {
      if ((1 + i * b) % a == 0) {
        flag = true;
        break;
      }
    }
    if (flag)
      printf("Finite\n");
    else
      printf("Infinite\n");
  }
  return 0;
}
