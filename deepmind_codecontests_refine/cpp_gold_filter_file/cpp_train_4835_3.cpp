#include <bits/stdc++.h>
using namespace std;
using namespace std;
const int INF = 2147483647;
const int INF2 = 0x3f3f3f3f;
const long long INF64 = 3e18;
const double INFD = 1e30;
const double EPS = 1e-10;
const long double PI = acosl(-1);
const int MOD = 1e9 + 7;
template <typename T>
inline T read() {
  T X = 0, w = 0;
  char ch = 0;
  while (!isdigit(ch)) {
    w |= ch == '-';
    ch = getchar();
  }
  while (isdigit(ch)) X = (X << 3) + (X << 1) + (ch ^ 48), ch = getchar();
  return w ? -X : X;
}
const int MAXN = 105;
const int MAXV = 60;
int n, m, k;
int dr[4] = {1, 0, -1, 0};
int dc[4] = {0, 1, 0, -1};
int dr2[8] = {1, 1, 1, -1, -1, -1, 0, 0};
int dc2[8] = {1, 0, -1, 1, 0, -1, 1, -1};
int CASE = 1;
bitset<102> mat[MAXN];
bitset<102> b;
int main() {
  scanf("%d%d%d", &n, &m, &k);
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) {
      int x = read<int>();
      if (x) mat[i].set(j);
    }
  }
  int ans = INF2;
  if (n <= k) {
    for (int s = 0; s < (1 << n); s++) {
      int t = 0;
      for (int i = 0; i < m; i++) {
        int cnt = 0;
        for (int j = 0; j < n; j++) {
          cnt += (mat[j][i] != ((s >> j) & 1));
        }
        t += min(cnt, n - cnt);
      }
      ans = min(ans, t);
    }
  } else {
    for (int i = 0; i < n; i++) {
      int t = 0;
      for (int j = 0; j < n; j++) {
        if (j != i) {
          auto t1 = mat[i] ^ mat[j];
          t += min(t1.count(), m - t1.count());
        }
      }
      ans = min(ans, t);
    }
  }
  if (ans > k) {
    printf("-1");
  } else {
    printf("%d\n", ans);
  }
  return 0;
}
