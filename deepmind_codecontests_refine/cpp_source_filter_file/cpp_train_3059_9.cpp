#include <bits/stdc++.h>
using namespace std;
int main() {
  int p;
  while (~scanf("%d", &p)) {
    int result = 0;
    for (int x = 2; x < p; x++) {
      int t = 1;
      bool valid = true;
      for (int i = 1; i < p - 1; i++) {
        t = (t * x) % p;
        if (t == 1) {
          valid = false;
          break;
        }
      }
      if (!valid) continue;
      t = (t * x) % p;
      if (t == 1) result++;
    }
    printf("%d\n", result);
  }
  return 0;
}
