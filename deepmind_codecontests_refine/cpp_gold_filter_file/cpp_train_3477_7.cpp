#include <bits/stdc++.h>
using namespace std;
int r, n;
pair<int, int> C[103];
int G[103][2], H[103];
int A[3 * 103];
int main() {
  scanf("%d", &r);
  scanf("%d", &n);
  for (int i = 0; i < (n); ++i) {
    scanf("%d", &C[i].first);
    scanf("%d", &C[i].second);
    --C[i].first;
    --C[i].second;
  }
  for (int t = (1); t < (r); ++t) {
    memset(A, 0, sizeof(A));
    for (int k = (0); k < (t - 1); ++k) ++A[G[k][1] ^ G[t - k - 1][0]];
    for (int i = 0; i < (103); ++i)
      if (!A[i]) {
        G[t][0] = i;
        break;
      }
    memset(A, 0, sizeof(A));
    for (int k = (0); k < (t); ++k) ++A[G[k][1] ^ G[t - k - 1][1]];
    for (int k = (1); k < (t - 1); ++k) ++A[G[k][0] ^ G[t - k - 1][0]];
    for (int i = 0; i < (103); ++i)
      if (!A[i]) {
        G[t][1] = i;
        break;
      }
    memset(A, 0, sizeof(A));
    for (int k = (0); k < (t); ++k) ++A[G[k][1] ^ H[t - k - 1]];
    for (int k = (1); k < (t); ++k) ++A[G[k][0] ^ H[t - k - 1]];
    for (int i = 0; i < (103); ++i)
      if (!A[i]) {
        H[t] = i;
        break;
      }
  }
  if (n == 0) {
    for (int k = 0; k < (r); ++k)
      if ((H[k] ^ H[r - k - 1]) == 0) {
        printf("WIN\n");
        return 0;
      }
    printf("LOSE\n");
    return 0;
  }
  sort(C, C + n);
  int ans = 0;
  for (int i = 0; i < (r - 1); ++i)
    ans ^= G[C[i + 1].first - C[i].first - 1]
            [1 - abs(C[i + 1].second - C[i].second)];
  ans ^= H[r - 1 - C[n - 1].first];
  ans ^= H[C[0].first];
  if (ans)
    printf("WIN\n");
  else
    printf("LOSE\n");
}
