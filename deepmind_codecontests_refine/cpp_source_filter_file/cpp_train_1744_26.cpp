#include <bits/stdc++.h>
using namespace std;
const int maxn = 1000 + 7;
bool f[maxn][maxn];
int reachable[maxn];
int main(int argc, char **argv) {
  int n;
  long long ans = 0;
  scanf("%d", &n);
  memset(reachable, 0x3f, sizeof(reachable));
  for (int i = 0; i <= 8; i++)
    for (int j = 0; j <= 48; j++)
      reachable[4 * i + 9 * j] = min(reachable[4 * i + 9 * j], i + j);
  int cnt = 0;
  for (int i = 0; i <= 8; i++)
    for (int j = 0; j <= 48; j++)
      if (i + j <= n) {
        try {
          for (int s = 1; 49 * s <= 4 * i + 9 * j; s++)
            if (reachable[4 * i + 9 * j - 49 * s] + s <= n) throw 0;
        } catch (int x) {
          continue;
        }
        ans += (n - (i + j)) + 1;
        cnt++;
      }
  printf("%d\n", ans);
  return 0;
}
