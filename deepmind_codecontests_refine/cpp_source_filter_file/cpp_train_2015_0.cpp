#include <bits/stdc++.h>
using namespace std;
int Nextint() {
  char ch = getchar();
  while (ch < '0' || ch > '9') ch = getchar();
  int x = 0;
  while (ch >= '0' && ch <= '9') {
    x = x * 10 + ch - '0';
    ch = getchar();
  }
  return x;
}
const int maxn = 3000100;
char S[maxn];
int K, N, L[5555], R[5555];
int sum[maxn * 5], F[maxn];
char S1[maxn];
void BLD(int t, int l, int r) {
  sum[t] = r - l + 1;
  if (l == r) return;
  int mid = l + r >> 1;
  BLD(t * 2, l, mid);
  BLD(t * 2 + 1, mid + 1, r);
}
int find(int t, int l, int r, int x) {
  if (l == r) return l;
  if (sum[t * 2] >= x) return find(t * 2, l, l + r >> 1, x);
  return find(t * 2 + 1, (l + r >> 1) + 1, r, x - sum[t * 2]);
}
void mfy(int t, int l, int r, int x) {
  if (r < x || x < l) return;
  sum[t]--;
  if (l == r) return;
  int mid = l + r >> 1;
  if (x <= mid)
    mfy(t * 2, l, mid, x);
  else
    mfy(t * 2 + 1, mid + 1, r, x);
}
int main() {
  scanf("%s\n", S + 1);
  scanf("%d", &K);
  scanf("%d", &N);
  for (int i = 1; i <= N; i++) scanf("%d%d", &L[i], &R[i]);
  BLD(1, 1, K);
  for (int i = N; i > 0 || (K < 3000000 && i > 0); i--)
    if (R[i] < sum[1]) {
      int D = R[i] - L[i] + 1;
      int ts = L[i] + 1;
      if (ts > R[i]) ts = L[i];
      for (int j = 1; j <= D && sum[1] > R[i]; j++) {
        int tk = find(1, 1, K, ts);
        int tt = find(1, 1, K, R[i] + 1);
        F[tt] = tk;
        mfy(1, 1, K, tt);
        ts += 2;
        if (ts > R[i]) ts = L[i];
      }
    }
  if (K > 1000000) {
    printf("%d %d\n", sum[0], N);
    return 0;
    printf("%d %d\n", K, strlen(S + 1));
    int tl = 0;
    for (int i = 1; i <= K; i++)
      if (F[i])
        S1[i] = S1[F[i]];
      else
        S1[i] = S[++tl];
    S1[K + 1] = 0;
    printf("%s\n", S1 + 1);
    return 0;
  }
  int tl = 0;
  for (int i = 1; i <= K; i++)
    if (F[i])
      S1[i] = S1[F[i]];
    else
      S1[i] = S[++tl];
  S1[K + 1] = 0;
  printf("%s\n", S1 + 1);
  return 0;
}
