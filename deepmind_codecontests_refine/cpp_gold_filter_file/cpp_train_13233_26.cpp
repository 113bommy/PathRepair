#include <bits/stdc++.h>
using namespace std;
const int dell[8][2] = {{1, 2},  {1, -2},  {2, 1},  {2, -1},
                        {-1, 2}, {-1, -2}, {-2, 1}, {-2, -1}};
long long mod = 1e9 + 7;
const long long inf = (1LL << 31) - 1;
const int maxn = 1e6 + 7;
const int maxm = 1e6 + 7;
const double eps = 1e-8;
const double pi = acos(-1.0);
const int csize = 22;
int n, k, m, ar[maxn];
int xl[maxn], num[maxn];
int main() {
  scanf("%d", &n);
  for (int i = 1; i <= n; i++) scanf("%d", ar + i);
  long long s = 0;
  for (int i = 1; i <= n; i++) s += ar[i];
  memset(num, 0, sizeof(num));
  for (int i = 1; i <= n; i++) {
    num[ar[i]]++;
  }
  int ans = 0;
  for (int i = 1; i <= n; i++) {
    if ((s - ar[i]) % 2 == 0) {
      if ((s - ar[i]) / 2 < maxn) {
        int x = (s - ar[i]) / 2;
        if (num[x] >= 2 || num[x] == 1 && x != ar[i]) xl[++ans] = i;
      }
    }
  }
  printf("%d\n", ans);
  for (int i = 1; i <= ans; i++) printf("%d%c", xl[i], i == ans ? '\n' : ' ');
  return 0;
}
