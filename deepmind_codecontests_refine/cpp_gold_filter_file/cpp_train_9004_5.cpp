#include <bits/stdc++.h>
using LL = long long;
int L[1001000], R[1001000], C[1001000], H[1001000];
int main() {
  int n;
  while (std::cin >> n) {
    for (int i = 1; i <= n; i++) {
      scanf("%d", &H[i]);
    }
    memset(L, 0, sizeof(L));
    memset(R, 0, sizeof(R));
    memset(C, 0, sizeof(C));
    std::rotate(H + 1, std::max_element(H + 1, H + n + 1), H + n + 1);
    LL ans = 0;
    for (int i = 2; i <= n; i++) {
      L[i] = i - 1;
      while (L[i] && H[i] > H[L[i]]) {
        L[i] = L[L[i]];
      }
      if (H[i] == H[L[i]]) {
        C[i] = C[L[i]] + 1;
        L[i] = L[L[i]];
      }
      ans += C[i];
    }
    for (int i = n - 1; i >= 1; i--) {
      R[i] = i + 1;
      while (R[i] && H[i] >= H[R[i]]) {
        R[i] = R[R[i]];
      }
    }
    for (int i = 1; i <= n; i++) {
      if (H[i] != H[1]) {
        ans += 2;
        if (L[i] == 1 && R[i] == 0) {
          ans--;
        }
      }
    }
    std::cout << ans << std::endl;
  }
  return 0;
}
