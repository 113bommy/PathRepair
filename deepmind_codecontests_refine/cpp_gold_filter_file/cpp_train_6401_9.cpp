#include <bits/stdc++.h>
using namespace std;
int A[300010], s[300010];
int L[300010], R[300010];
int T[300010], tl;
int w[1000010];
struct HH {
  int x, t;
} H;
vector<HH> z[300010];
int main() {
  int n, mod, i, j, l, r;
  long long ans = 0;
  scanf("%d%d", &n, &mod);
  for (i = 1; i <= n; i++) {
    scanf("%d", &A[i]);
    s[i] = (s[i - 1] + A[i]) % mod;
    while (tl && A[T[tl]] < A[i]) tl--;
    if (tl)
      L[i] = T[tl] + 1;
    else
      L[i] = 1;
    T[++tl] = i;
  }
  tl = 0;
  for (i = n; i >= 1; i--) {
    while (tl && A[T[tl]] <= A[i]) tl--;
    if (tl)
      R[i] = T[tl] - 1;
    else
      R[i] = n;
    T[++tl] = i;
  }
  for (i = 1; i <= n; i++) {
    l = L[i];
    r = R[i];
    if (i <= (l + r) >> 1)
      for (j = l - 1; j <= i - 1; j++) {
        H.x = (A[i] + s[j]) % mod;
        H.t = 1;
        z[r].push_back(H);
        H.t = -1;
        z[i - 1].push_back(H);
      }
    else
      for (j = i; j <= r; j++) {
        H.x = (s[j] - A[i] % mod + mod) % mod;
        H.t = 1;
        z[i - 1].push_back(H);
        H.t = -1;
        if (l != 1) z[l - 2].push_back(H);
      }
  }
  for (i = 0; i <= n; i++) {
    w[s[i]]++;
    for (j = 0; j < z[i].size(); j++) {
      H = z[i][j];
      ans += H.t * w[H.x];
    }
  }
  printf("%I64d\n", ans - n);
  return 0;
}
