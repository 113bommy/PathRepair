#include <bits/stdc++.h>
using namespace std;
const int inf = 0x3f3f3f3f;
const int _inf = 0xc0c0c0c0;
const long long INF = 0x3f3f3f3f3f3f3f3f;
const long long _INF = 0xc0c0c0c0c0c0c0c0;
const long long mod = (int)1e9 + 7;
const int N = 1e5 + 100;
int n, k;
bool P(int x, int y) {
  printf("%d %d\n", x, y);
  --n;
  if (n == 0) return true;
  return false;
}
void Ac() {
  if (k > 1ll * n * (n - 1)) {
    puts("NO");
    return;
  }
  puts("YES");
  for (int i = 1; i < k; ++i) {
    int x = 1, y = x + 1;
    while (y <= k) {
      if (P(x, y)) return;
      if (P(y, x)) return;
      y++;
    }
  }
}
int main() {
  while (~scanf("%d%d", &n, &k)) {
    Ac();
  }
  return 0;
}
