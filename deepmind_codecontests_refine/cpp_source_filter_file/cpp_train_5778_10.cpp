#include <bits/stdc++.h>
using namespace std;
int main() {
  int A[6], l, r;
  long long int ans = 0;
  for (int i = 0; i < 6; i++) {
    scanf("%d", &A[i]);
  }
  l = 2;
  r = 4;
  ans = 0;
  while (1) {
    if (A[l] > A[r]) {
      if (A[r] != 0) {
        ans += (2 * A[3] + 1);
        A[3]++;
        A[r]--;
        A[l]--;
      } else {
        if (A[l] != 0) {
          ans += 2 * A[3];
          A[l]--;
          A[5]--;
        }
      }
    } else if (A[l] == A[r]) {
      if (A[l] == 0) {
        if (A[1] > 0 && A[5] > 0) {
          ans += (2 * A[3] - 1);
          A[3]--;
          A[5]--;
          A[1]--;
        } else {
          printf("%lld\n", ans);
          break;
        }
      } else {
        ans += (2 * A[3] + 1);
        A[3]++;
        A[r]--;
        A[l]--;
      }
    } else {
      if (A[l] != 0) {
        ans += (2 * A[3] + 1);
        A[3]++;
        A[r]--;
        A[l]--;
      } else {
        if (A[r] != 0) {
          ans += 2 * A[3];
          A[r]--;
          A[5]--;
        }
      }
    }
  }
  return 0;
}
