#include <bits/stdc++.h>
using namespace std;
const int maxn = 3e5 + 5;
int n, r[maxn], f1[maxn][20], f2[maxn][20], fl[maxn][20], fr[maxn][20],
    Log[maxn];
int chk1(int a, int b) {
  return r[(a - 1) % n + 1] - a > r[(b - 1) % n + 1] - b ? a : b;
}
int chk2(int a, int b) {
  return r[(a - 1) % n + 1] + a > r[(b - 1) % n + 1] + b ? a : b;
}
int query1(int l, int r) {
  int w = Log[r - l + 1];
  return chk1(f1[l][w], f1[r - (1 << w) + 1][w]);
}
int query2(int l, int r) {
  int w = Log[r - l + 1];
  return chk2(f2[l][w], f2[r - (1 << w) + 1][w]);
}
int main() {
  for (int i = 1; i <= 18; i++) Log[1 << i]++;
  for (int i = 1; i <= 300000; i++) Log[i] += Log[i - 1];
  cin >> n;
  if (n == 1) {
    cout << 1;
    return 0;
  }
  for (int i = 1; i <= n; i++) cin >> r[i];
  for (int i = 1; i <= n * 3; i++) f1[i][0] = f2[i][0] = i;
  for (int j = 1; j <= 18; j++)
    for (int i = 1; i <= n * 3; i++)
      if (i + (1 << j) - 1 <= n * 3)
        f1[i][j] = chk1(f1[i][j - 1], f1[i + (1 << j - 1)][j - 1]),
        f2[i][j] = chk2(f2[i][j - 1], f2[i + (1 << j - 1)][j - 1]);
  for (int i = 1; i <= n * 3; i++)
    fl[i][0] = i - r[(i - 1) % n + 1], fr[i][0] = i + r[(i - 1) % n + 1];
  for (int j = 1; j <= 18; j++)
    for (int i = 1; i <= n * 3; i++) {
      int L = fl[i][j - 1], R = fr[i][j - 1];
      if (R - L + 1 >= n) {
        fl[i][j] = L, fr[i][j] = R;
        continue;
      }
      int w1 = query1(L, R), w2 = query2(L, R);
      fl[i][j] = min(fl[w1][j - 1], fl[w2][j - 1]);
      fr[i][j] = max(fr[w1][j - 1], fr[w2][j - 1]);
    }
  for (int i = 1; i <= n; i++) {
    int ans = 0, L = i + n, R = i + n;
    for (int j = 18; j >= 0; j--) {
      int w1 = query1(L, R), w2 = query2(L, R);
      int nl = min(fl[w1][j], fl[w2][j]), nr = max(fr[w1][j], fr[w2][j]);
      if (nr - nl + 1 < n) L = nl, R = nr, ans += 1 << j;
    }
    cout << ans + 1 << ' ';
  }
  return 0;
}
