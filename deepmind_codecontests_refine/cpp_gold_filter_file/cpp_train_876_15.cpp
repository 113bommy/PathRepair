#include <bits/stdc++.h>
using namespace std;
template <class T>
inline void read(T& x) {
  bool fu = 0;
  char c;
  for (c = getchar(); c <= 32; c = getchar())
    ;
  if (c == '-') fu = 1, c = getchar();
  for (x = 0; c > 32; c = getchar()) x = x * 10 + c - '0';
  if (fu) x = -x;
};
template <class T>
inline void read(T& x, T& y) {
  read(x);
  read(y);
}
template <class T>
inline void read(T& x, T& y, T& z) {
  read(x);
  read(y);
  read(z);
}
inline char getc() {
  char c;
  for (c = getchar(); c <= 32; c = getchar())
    ;
  return c;
}
const int N = 200000;
int n, m, i, j, k, p, g;
bool v[N + 10];
int z[2010];
int val[N + 1];
pair<int, int> a[N + 10];
int l[N + 10], sl[N + 10];
int dp[N + 10], gg[N + 10];
int s[N + 10];
int L[2010], R[2010], tL[2010], tR[2010];
int L0[2010], R0[2010];
int get(int x, int y) { return s[y] - s[x - 1]; }
int main() {
  read(n, m);
  int x;
  for (i = 1; i <= n; i++) read(x), v[x] = 1;
  for (i = 1; i <= m; i++) read(z[i]), val[z[i]]++;
  sort(z + 1, z + 1 + m);
  for (i = 1; i <= N; i++) val[i] += val[i - 1];
  for (i = 1; i <= N; i++)
    if (v[i]) {
      for (j = i; v[j]; j++)
        ;
      j--;
      if (v[i]) a[++g] = make_pair(i, j);
      i = j + 1;
    }
  for (i = 1; i <= g; i++) l[i] = a[i].second - a[i].first + 1;
  for (i = 1; i <= g; i++) sl[i] = sl[i - 1] + l[i];
  for (i = 1; i <= g; i++) {
    for (j = 1; j <= m; j++) {
      if (sl[i] < a[i].second - z[j] + 1 || z[j] > a[i].second)
        L[j] = 0;
      else {
        int l, r, mid;
        l = 1, r = i;
        if (L[j - 1] != 0) l = L[j - 1];
        if (i > 1 && L0[j] != 0) r = min(r, L0[j]);
        for (; l < r;) {
          mid = (l + r + 1) / 2;
          if (sl[i] - sl[mid - 1] >= a[i].second - z[j] + 1)
            l = mid;
          else
            r = mid - 1;
        }
        L[j] = l;
      }
    }
    for (j = 1; j <= m; j++) {
      if (sl[g] - sl[i - 1] < z[j] - a[i].first + 1 || z[j] < a[i].first)
        R[j] = g + 1;
      else {
        int l, r, mid;
        l = i, r = g;
        if (R[j - 1] != g + 1) l = R[j - 1];
        if (i > 1 && R0[j] != g + 1) r = min(r, R0[j]);
        for (; l < r;) {
          mid = (l + r) / 2;
          if (sl[mid] - sl[i - 1] >= z[j] - a[i].first + 1)
            r = mid;
          else
            l = mid + 1;
        }
        R[j] = l;
      }
    }
    dp[i] = max(dp[i], dp[i - 1]);
    for (j = 1; j <= m; j++)
      if (L[j])
        dp[i] = max(dp[i], dp[L[j] - 1] + val[a[i].second] - val[z[j] - 1]);
    for (j = 1; j <= m; j++)
      if (R[j] <= g)
        gg[R[j]] = max(gg[R[j]], dp[i] + val[z[j]] - val[a[i].second]);
    dp[i] = max(dp[i], gg[i]);
    memcpy(L0, L, sizeof(L));
    memcpy(R0, R, sizeof(R));
  }
  printf("%d\n", dp[g]);
  return 0;
}
