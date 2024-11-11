#include <bits/stdc++.h>
using namespace std;
const int MOD = 1000000007;
const int MAXN = 1000000;
int n, k;
bool visited[MAXN + 3];
int len[MAXN + 3];
int main() {
  scanf("%d %d", &n, &k);
  int ans = 1;
  if (k != 1) {
    int r = 1;
    int v = k;
    while (v != 1 && v != 0) {
      v = (int)(((long long)v * k) % n);
      r++;
    }
    for (int i = 0; i < (n - 1) / r; i++)
      ans = (int)(((long long)ans * n) % MOD);
  } else {
    for (int i = 0; i < n; i++) ans = (int)(((long long)ans * n) % MOD);
  }
  printf("%d\n", ans);
  return 0;
}
