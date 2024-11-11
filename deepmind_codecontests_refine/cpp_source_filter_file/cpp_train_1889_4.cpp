#include <bits/stdc++.h>
using namespace std;
const int INF = 0x7fffffff;
const int inf = 0x3f3f3f3f;
const int maxn = 200005;
const int N = 105;
void read(long long &x) {
  long long f = 1;
  x = 0;
  char s = getchar();
  while (s < '0' || s > '9') {
    if (s == '-') f = -1;
    s = getchar();
  }
  while (s >= '0' && s <= '9') {
    x = x * 10 + s - '0';
    s = getchar();
  }
  x *= f;
}
long long n, a[300005], bi = 0, si = 0, ans = 0;
int main() {
  read(n);
  for (int i = 0; i < n; ++i) {
    read(a[i]);
    bi = a[i] / 2;
    si += a[i] % 2;
    if (si >= bi) {
      ans += bi;
      si -= bi;
      bi = 0;
    } else {
      ans += si;
      bi -= si;
      si = 0;
      ans += (bi / 3) * 2;
      bi /= 3;
      if (bi == 1)
        si += 2;
      else if (bi == 2) {
        ans++;
        si += 1;
      }
    }
  }
  cout << ans << endl;
}
