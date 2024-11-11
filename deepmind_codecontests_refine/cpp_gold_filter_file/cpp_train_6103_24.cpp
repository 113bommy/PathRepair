#include <bits/stdc++.h>
using namespace std;
const int oo = 0x3f3f3f3f;
const long long ooo = 9223372036854775807ll;
const int _cnt = 1000 * 1000 + 7;
const int _p = 1000 * 1000 * 1000 + 7;
const int N = 200105;
const double PI = acos(-1.0);
const double eps = 1e-6;
int o(int x) { return x % _p; }
int gcd(int a, int b) { return b ? gcd(b, a % b) : a; }
int lcm(int a, int b) { return a / gcd(a, b) * b; }
void file_put() {
  freopen("filename.in", "r", stdin);
  freopen("filename.out", "w", stdout);
}
int ans[N], p[N], q[N], a[N], b[N], n, m, t = 0, cnt = 0;
int main() {
  scanf("%d", &n);
  for (int i = (0); i <= (n - 1); ++i) printf("? %d %d\n", 0, i), cin >> a[i];
  for (int i = (0); i <= (n - 1); ++i) printf("? %d %d\n", i, 0), cin >> b[i];
  for (int i = (0); i <= (n - 1); ++i) {
    for (int j = (0); j <= (n - 1); ++j) q[j] = a[j] ^ i;
    for (int j = (0); j <= (n - 1); ++j) p[j] = b[j] ^ q[0];
    t = 1;
    for (int j = (0); j <= (n - 1); ++j)
      if (p[j] >= n || q[j] >= n || p[q[j]] != j) {
        t = 0;
        break;
      }
    cnt += t;
    if (t && cnt == 1)
      for (int j = (0); j <= (n - 1); ++j) ans[j] = p[j];
  }
  printf("!\n%d\n", cnt);
  for (int i = (0); i <= (n - 1); ++i) printf("%d ", ans[i]);
  printf("\n");
  return 0;
}
