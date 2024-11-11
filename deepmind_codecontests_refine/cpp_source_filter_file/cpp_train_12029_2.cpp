#include <bits/stdc++.h>
using namespace std;
int main() {
  int n;
  scanf("%d", &n);
  for (int i = 0; i <= 810; i++) {
    if (i * 1234567 > n) break;
    for (int j = 0; j <= 8100; j++) {
      if (i * 1234567 + j * 123456 > n) break;
      int k = n - i * 1234567 + j * 123456;
      if (k % 1234 == 0) {
        puts("YES");
        return 0;
      }
    }
  }
  puts("NO");
  return 0;
}
