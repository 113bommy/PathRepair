#include <bits/stdc++.h>
using namespace std;
int main() {
  int T;
  cin >> T;
  while (T--) {
    int A, B, C, ansa, ansb, ansc;
    int ans = 1e9 + 10;
    scanf("%d%d%d", &A, &B, &C);
    for (int b = C + B; b >= 1; --b) {
      int c = C / b * b;
      if (C % b > b - C % b) c += b;
      for (int k = 1; k * k <= b; ++k) {
        if (b % k) continue;
        int a = b / k;
        int tmp = abs(A - a) + abs(B - b) + abs(C - c);
        if (tmp < ans) {
          ans = tmp;
          ansa = a;
          ansb = b;
          ansc = c;
        }
        tmp = abs(A - k) + abs(B - b) + abs(C - c);
        if (tmp < ans) {
          ans = tmp;
          ansa = k;
          ansb = b;
          ansc = c;
        }
      }
    }
    printf("%d\n%d %d %d\n", ans, ansa, ansb, ansc);
  }
}
