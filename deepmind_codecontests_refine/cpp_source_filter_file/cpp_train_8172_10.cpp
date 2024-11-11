#include <bits/stdc++.h>
using namespace std;
template <class T>
inline T countbit(T n) {
  return n ? 1 + countbit(n & (n - 1)) : 0;
}
template <class T>
inline T sqr(T a) {
  return a * a;
}
template <class T>
inline void checkmin(T &a, T b) {
  if (a == -1 || a > b) a = b;
}
template <class T>
inline void checkmax(T &a, T b) {
  if (a < b) a = b;
}
const double eps = 1e-11;
const double Pi = acos(-1.0);
int dx[] = {-1, 0, 1, 0};
int dy[] = {0, 1, 0, -1};
const int INF = 0x1fffffff;
const int N = 100007;
int n, ans;
int a[3000], b[3000];
int main() {
  scanf("%d", &n);
  for (int i = (0); i < (n); i++) {
    int x, y;
    scanf("%d%d", &x, &y);
    ans += a[x + 1000 - y]++;
    ans += b[y + 1000 - x]++;
  }
  cout << ans << endl;
  return 0;
}
