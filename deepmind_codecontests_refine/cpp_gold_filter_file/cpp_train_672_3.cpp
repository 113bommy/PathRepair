#include <bits/stdc++.h>
using namespace std;
const int INF = 0x3f3f3f3f;
const int maxn = (1e5 + 100) * 5;
int n, q, X;
int A[maxn], have[maxn];
int v[20], kind[maxn], num[maxn];
int main() {
  while (~scanf("%d%d", &n, &q)) {
    for (int i = 1; i <= n; i++) scanf("%d", &A[i]);
    memset(have, 0, sizeof have);
    memset(num, 0, sizeof num);
    long long ans = 0;
    long long C = 0;
    while (q--) {
      scanf("%d", &X);
      int k = 0;
      int g = A[X];
      for (int i = 2; i * i <= g; i++) {
        if (g % i == 0) {
          while (g % i == 0) g /= i;
          v[k++] = i;
        }
      }
      if (g > 1) v[k++] = g;
      if (!have[X]) {
        have[X] = 1;
        C++;
        for (int i = 1; i < (1 << k); i++) {
          int c = 0, l = 1;
          for (int j = 0; j < k; j++) {
            if (i & (1 << j)) {
              c++;
              l *= v[j];
            }
          }
          num[l]++;
          kind[l] = c;
          if (c & 1) {
            ans = ans - (num[l] - 1) * (num[l] - 2) / 2;
            ans = ans + (num[l] - 1) * num[l] / 2;
          } else {
            ans = ans + (num[l] - 1) * (num[l] - 2) / 2;
            ans = ans - (num[l] - 1) * num[l] / 2;
          }
        }
        printf("%I64d\n", C * (C - 1) / 2 - ans);
      } else {
        have[X] = 0;
        C--;
        for (int i = 1; i < (1 << k); i++) {
          int c = 0, l = 1;
          for (int j = 0; j < k; j++) {
            if (i & (1 << j)) {
              c++;
              l *= v[j];
            }
          }
          num[l]--;
          kind[l] = c;
          if (c & 1) {
            ans = ans - (num[l] + 1) * (num[l]) / 2;
            ans = ans + (num[l] - 1) * num[l] / 2;
          } else {
            ans = ans + (num[l] + 1) * (num[l]) / 2;
            ans = ans - (num[l] - 1) * num[l] / 2;
          }
        }
        printf("%I64d\n", C * (C - 1) / 2 - ans);
      }
    }
  }
  return 0;
}
