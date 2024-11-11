#include <bits/stdc++.h>
#pragma comment(linker, "/STACK:102400000,102400000")
using namespace std;
const int INF = 0x3f3f3f3f;
const long long INFF = 0x3f3f;
const double pi = acos(-1.0);
const double inf = 1e18;
const double eps = 1e-8;
const long long mod = (long long)1e9 + 7;
const unsigned long long mx = 133333331;
inline void RI(int &x) {
  char c;
  while ((c = getchar()) < '0' || c > '9')
    ;
  x = c - '0';
  while ((c = getchar()) >= '0' && c <= '9') x = (x << 3) + (x << 1) + c - '0';
}
int a[1000005];
int vis[1000005];
long long gcd(long long a, long long b) {
  if (!b) return a;
  return gcd(b, a % b);
}
long long lcm(long long a, long long b) { return a * b / gcd(a, b); }
int main() {
  int n;
  scanf("%d", &n);
  memset(vis, 0, sizeof(vis));
  long long ans = -INFF;
  int flag = 0;
  for (int i = 1; i <= n; i++) scanf("%d", &a[i]);
  for (int i = 1; i <= n; i++) {
    if (!vis[i]) {
      long long tmp = 1;
      int k = a[i];
      vis[i] = 1;
      while (k != i) {
        vis[k] = 1;
        k = a[k];
        tmp++;
        if (tmp > n) {
          flag = 1;
          break;
        }
      }
      if (tmp >= 1 && tmp < n) {
        if (tmp % 2 == 0) tmp /= 2;
        if (ans == -INFF)
          ans = tmp;
        else
          ans = lcm(tmp, ans);
      }
    }
  }
  if (!flag)
    cout << ans << endl;
  else
    puts("-1");
  return 0;
}
