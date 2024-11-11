#include <bits/stdc++.h>
using namespace std;
int readint() {
  int x = 0, y = 1;
  char c = getchar();
  while ((c < '0' || c > '9') && c != '-') c = getchar();
  if (c == '-') y = -1, c = getchar();
  while (c >= '0' && c <= '9') x = x * 10 + c - '0', c = getchar();
  return x * y;
}
struct Br {
  int p, c, l;
} br[110];
int n, K, T = 100;
int npr[200010], uk[110];
int ans = 0x3f3f3f3f;
int main() {
  srand(19260817);
  cin >> n >> K;
  for (int i = 1; i <= n; i++) cin >> br[i].p >> br[i].c >> br[i].l;
  for (int i = 2; i <= 200000; i++)
    if (!npr[i])
      for (int j = i * 2; j <= 200000; j += i) npr[j] = 1;
  int sz = n;
  while (T--) {
    random_shuffle(br + 1, br + sz + 1);
    int tp = 0, mx = 0, sum = 0;
    int i;
    for (i = 1; i <= sz; i++) {
      int j = 1;
      while (j <= tp && npr[uk[j] + br[i].c]) j++;
      if (j > tp) {
        uk[++tp] = br[i].c, mx = max(mx, br[i].l), sum += br[i].p;
        if (sum >= K) {
          ans = min(ans, mx);
          break;
        }
      }
    }
    if (i <= sz) {
      int zz = 0;
      for (int j = 1; j <= sz; j++)
        if (br[j].l < ans) br[++zz] = br[j];
      sz = zz;
    }
  }
  cout << (ans > 0x3f3f3f3f ? -1 : ans) << '\n';
  return 0;
}
