#include <bits/stdc++.h>
using namespace std;
const int MAXN = 150000 + 100;
const int inf = 0x3fffffff;
int n, m, d, head, tail;
int a[MAXN], b[MAXN], t[MAXN];
long long dp[2][MAXN];
struct node {
  int index;
  long long val;
} que[MAXN];
int main() {
  while (~scanf("%d%d%d", &n, &m, &d)) {
    long long ans = 0;
    for (int i = 1; i <= m; i++) {
      scanf("%d%d%d", &a[i], &b[i], &t[i]);
      ans += b[i];
    }
    for (int i = 1; i <= n; i++) dp[0][i] = abs(a[1] - i);
    int now = 0;
    long long k;
    for (int j = 2; j <= m; j++) {
      k = t[j] - t[j - 1];
      k *= d;
      if (k > n) k = n;
      head = tail = 0;
      for (int i = 1; i <= k; i++) {
        while (head < tail && dp[now][i] < que[tail - 1].val) tail--;
        que[tail].val = dp[now][i];
        que[tail++].index = i;
      }
      for (int i = k; i <= n; i++) {
        int l, r;
        l = i - k;
        r = i + k;
        if (l <= 0) l = 1;
        while (head < tail && que[head].index < l) head++;
        if (r <= n) {
          while (head < tail && dp[now][r] < que[tail - 1].val) tail--;
          que[tail].val = dp[now][r];
          que[tail++].index = r;
        }
        dp[now ^ 1][i] = que[head].val + abs(a[j] - i);
      }
      now ^= 1;
    }
    long long Min = dp[now][1];
    for (int i = 2; i <= n; i++) Min = min(Min, dp[now][i]);
    cout << ans - Min << endl;
  }
  return 0;
}
