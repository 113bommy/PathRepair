#include <bits/stdc++.h>
using namespace std;
int i, j, k, l, s, n, m, father[100001], komp[100001], col_sv_komp[100001], ans,
    x, y;
inline int get(int x) {
  if (father[x] == x) return x;
  return father[x] = get(father[x]);
}
inline bool check(int x) {
  while (x) {
    if (x % 10 != 7 && x % 10 != 4) return false;
    x /= 10;
  };
  return true;
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie();
  cout.tie();
  scanf("%d%d", &n, &m);
  for (i = 1; i <= n; i++) father[i] = i;
  for (i = 1; i <= m; i++) scanf("%d%d", &x, &y), father[get(x)] = get(y);
  for (i = 1; i <= n; i++) komp[get(i)]++;
  for (i = 1; i <= n; i++) col_sv_komp[komp[i]]++;
  komp[0] = 0;
  for (i = 1; i <= n; i++) komp[i] = 1000000000;
  ans = 1000000000;
  for (int i = 1; i <= n; i++) {
    if (col_sv_komp[i]) {
      for (int j = 1; j <= col_sv_komp[i]; j *= 2) {
        for (int k = n - j * i; k >= 0; k--) {
          komp[k + j * i] = min(komp[k + j * i], komp[k] + j);
        };
      };
    };
  };
  for (i = 4; i <= n; i += 3)
    if (check(i)) ans = min(ans, komp[i] - 1);
  if (ans > n) ans = -1;
  printf("%d\n", ans);
};
