#include <bits/stdc++.h>
using namespace std;
#pragma warning(disable : 4996)
const int maxn = 1005;
long long y[maxn];
bool vis[maxn];
int n;
void solve(long long k, int temp) {
  long long yy = y[temp];
  vis[temp] = 1;
  for (int i = 1; i <= n; i++) {
    if (1LL * 2 * (y[i] - yy) == k * (i - 1)) vis[i] = 1;
  }
}
bool check() {
  for (int i = 1; i <= n; i++)
    if (!vis[i]) return 0;
  return 1;
}
int main() {
  scanf("%d", &n);
  for (int i = 1; i <= n; i++) {
    scanf("%lld", &y[i]);
  }
  long long k[4];
  k[1] = 2 * (y[2] - y[1]);
  k[2] = (y[3] - y[1]);
  k[3] = 2 * (y[3] - y[2]);
  for (int i = 1; i <= 3; i++) {
    memset(vis, 0, sizeof(vis));
    if (i == 1 || i == 2)
      solve(k[i], 1);
    else
      solve(k[i], 2);
    if (check()) {
      puts("NO");
      return 0;
    }
    int temp = -1;
    bool flag = true;
    for (int j = 1; j <= n; j++)
      if (vis[j] == 0) {
        if (temp == -1)
          temp = j;
        else {
          if (1LL * 2 * (y[j] - y[temp]) != k[i] * (j - temp)) {
            flag = false;
            break;
          }
        }
      }
    if (flag) {
      puts("YES");
      return 0;
    }
  }
  puts("NO");
  return 0;
}
