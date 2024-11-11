#include <bits/stdc++.h>
using namespace std;
template <class T>
T min(T a, T b, T c) {
  return min(a, min(b, c));
}
template <class T>
T max(T a, T b, T c) {
  return max(a, max(b, c));
}
template <class T>
void read(vector<T> &v) {
  T x;
  cin >> x;
  v.push_back(x);
}
int f[1000005][20], lp[1000005];
int main() {
  for (int i = (2); i <= (1000005 - 1); ++i) {
    if (lp[i] == 0) {
      for (int j = (i); j <= (1000005 - 1); j += i) {
        if (!lp[j]) lp[j] = i;
      }
    }
  }
  for (int j = (0); j <= (20 - 1); ++j) f[0][j] = (j == 0) ? 1 : 2;
  for (int i = (1); i <= (1000005 - 1); ++i) {
    f[i][0] = f[i - 1][0];
    for (int j = (1); j <= (20 - 1); ++j)
      f[i][j] = (f[i][j - 1] + f[i - 1][j]) % 1000000007;
  }
  int q;
  scanf("%d", &q);
  for (int i = (1); i <= (q); ++i) {
    int r, n;
    scanf("%d%d", &r, &n);
    int ans = 1;
    while (lp[n]) {
      int x = lp[n], cnt = 0;
      while (lp[n] == x) ++cnt, n /= x;
      ans = ((long long)ans * f[r][cnt]) % 1000000007;
    }
    printf("%d\n", ans);
  }
  return 0;
}
