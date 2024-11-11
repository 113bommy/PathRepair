#include <bits/stdc++.h>
template <typename T1, typename T2>
inline void chmin(T1 &x, T2 b) {
  if (b < x) x = b;
}
template <typename T1, typename T2>
inline void chmax(T1 &x, T2 b) {
  if (b > x) x = b;
}
const int inf = 1039074182;
const int B = 300;
using namespace std;
int n;
int a[100005];
int steps[100005][B + 5];
void solve() {
  int p, k;
  scanf("%d%d", &p, &k);
  p--;
  int res = 0;
  if (k <= B)
    res = steps[p][k];
  else {
    while (p < n) {
      p = p + a[p] + k;
      res++;
    }
  }
  printf("%d\n", res);
}
int main() {
  cin >> n;
  for (int i = 0; i < n; i++) {
    scanf("%d", a + i);
  }
  for (int i = n - 1; i >= 0; i--) {
    for (int j = 0; j < B; j++) {
      int nexti = i + j + a[i];
      steps[i][j] = 1 + (nexti >= n ? 0 : steps[nexti][j]);
    }
  }
  int q;
  cin >> q;
  while (q--) {
    solve();
  }
  return 0;
}
