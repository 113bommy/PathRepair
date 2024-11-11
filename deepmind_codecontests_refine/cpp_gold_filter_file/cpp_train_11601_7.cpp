#include <bits/stdc++.h>
using namespace std;
template <typename T, typename U>
inline void smin(T &a, U b) {
  if (a > b) a = b;
}
template <typename T, typename U>
inline void smax(T &a, U b) {
  if (a < b) a = b;
}
int power(int a, int b, int m, int ans = 1) {
  for (; b; b >>= 1, a = 1LL * a * a % m)
    if (b & 1) ans = 1LL * ans * a % m;
  return ans;
}
int n, m, k;
int build(int u, int v) {
  for (int i = 1; i <= u; i++) printf("(%d,1) ", i);
  for (int i = 2; i <= v; i++) printf("(%d,%d) ", u, i);
  return 0;
}
pair<int, int> p[5000];
int main() {
  scanf("%d%d%d", &n, &m, &k);
  p[1].first = 1;
  p[1].second = 1;
  for (int i = 2; i <= k; i++) {
    if (p[i - 1].first == n || p[i - 1].second == 1) {
      int s = p[i - 1].first + p[i - 1].second + 1;
      for (int j = 1; j <= n; j++) {
        if ((s - j) <= m) {
          p[i].first = j;
          p[i].second = s - j;
          break;
        }
      }
    } else {
      p[i].first = p[i - 1].first + 1;
      p[i].second = p[i - 1].second - 1;
    }
  }
  int num = 0;
  for (int i = 1; i <= k; i++) {
    num += p[i].first + p[i].second - 1;
  }
  cout << num << endl;
  for (int i = k; i >= 1; i--) {
    build(p[i].first, p[i].second);
    puts("");
  }
  return 0;
}
