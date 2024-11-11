#include <bits/stdc++.h>
using namespace std;
const int N = 2505;
char s[N][N];
int a[N][N], n, m, K;
int q1[N][10], q2[N][10];
int tQ1[10], tQ2[10], Q1[10], Q2[10];
long long ans;
void divide(int l, int r, int L, int R) {
  if (l == r && L == R) return ans += (a[L][l] == K), void(0);
  if (R - L + 1 <= r - l + 1) {
    int mid = (l + r) / 2, top = 0;
    divide(l, mid, L, R);
    divide(mid + 1, r, L, R);
    for (int i = (int)(L); i <= (int)(R); i++) {
      top = 0;
      q1[i][0] = mid;
      for (int j = (int)(mid); j >= (int)(l); j--)
        if (a[i][j] && top <= K) q1[i][++top] = j;
      for (; top <= K; q1[i][++top] = l - 1)
        ;
      top = 0;
      q2[i][0] = mid + 1;
      for (int j = (int)(mid + 1); j <= (int)(r); j++)
        if (a[i][j] && top <= K) q2[i][++top] = j;
      for (; top <= K; q2[i][++top] = r + 1)
        ;
    }
    for (int i = (int)(L); i <= (int)(R); i++) {
      Q1[0] = mid;
      Q2[0] = mid + 1;
      for (int j = (int)(1); j <= (int)(K + 1); j++)
        Q1[j] = l - 1, Q2[j] = r + 1;
      for (int j = (int)(i); j <= (int)(R); j++) {
        int p1, p2, p3;
        for (int k = (int)(1); k <= (int)(K + 1); k++)
          tQ1[k] = Q1[k], tQ2[k] = Q2[k];
        for (p1 = p2 = p3 = 1; p3 <= K + 1;)
          Q1[p3++] = (tQ1[p1] > q1[j][p2] ? tQ1[p1++] : q1[j][p2++]);
        for (p1 = p2 = p3 = 1; p3 <= K + 1;)
          Q2[p3++] = (tQ2[p1] < q2[j][p2] ? tQ2[p1++] : q2[j][p2++]);
        for (int k = (int)(0); k <= (int)(K); k++)
          ans += (Q1[k] - Q1[k + 1]) * (Q2[K - k + 1] - Q2[K - k]);
      }
    }
  } else {
    int mid = (L + R) / 2, top = 0;
    divide(l, r, L, mid);
    divide(l, r, mid + 1, R);
    for (int i = (int)(l); i <= (int)(r); i++) {
      top = 0;
      q1[i][0] = mid;
      for (int j = (int)(mid); j >= (int)(L); j--)
        if (a[j][i] && top <= K) q1[i][++top] = j;
      for (; top <= K; q1[i][++top] = L - 1)
        ;
      top = 0;
      q2[i][0] = mid + 1;
      for (int j = (int)(mid + 1); j <= (int)(R); j++)
        if (a[j][i] && top <= K) q2[i][++top] = j;
      for (; top <= K; q2[i][++top] = R + 1)
        ;
    }
    for (int i = (int)(l); i <= (int)(r); i++) {
      Q1[0] = mid;
      Q2[0] = mid + 1;
      for (int j = (int)(1); j <= (int)(K + 1); j++)
        Q1[j] = L - 1, Q2[j] = R + 1;
      for (int j = (int)(i); j <= (int)(r); j++) {
        int p1, p2, p3;
        for (int k = (int)(1); k <= (int)(K + 1); k++)
          tQ1[k] = Q1[k], tQ2[k] = Q2[k];
        for (p1 = p2 = p3 = 1; p3 <= K + 1;)
          Q1[p3++] = (tQ1[p1] > q1[j][p2] ? tQ1[p1++] : q1[j][p2++]);
        for (p1 = p2 = p3 = 1; p3 <= K + 1;)
          Q2[p3++] = (tQ2[p1] < q2[j][p2] ? tQ2[p1++] : q2[j][p2++]);
        for (int k = (int)(0); k <= (int)(K); k++)
          ans += (Q1[k] - Q1[k + 1]) * (Q2[K - k + 1] - Q2[K - k]);
      }
    }
  }
}
int main() {
  scanf("%d%d%d", &n, &m, &K);
  for (int i = (int)(1); i <= (int)(n); i++) scanf("%s", s[i] + 1);
  for (int i = (int)(1); i <= (int)(n); i++)
    for (int j = (int)(1); j <= (int)(n); j++) a[i][j] = s[i][j] - 48;
  divide(1, m, 1, n);
  printf("%lld\n", ans);
}
