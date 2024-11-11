#include <bits/stdc++.h>
using namespace std;
const int maxn = 1e5 + 10;
int arr[maxn];
int now[maxn];
int nowcnt[maxn];
int main() {
  int n, k, m;
  while (~scanf("%d%d%d", &n, &k, &m)) {
    bool single_color = true;
    for (int i = 1; i <= n; i++) scanf("%d", &arr[i]);
    for (int i = 2; i <= n; i++)
      if (arr[i] != arr[i - 1]) single_color = false;
    if (single_color) {
      printf("%d\n", (long long)n * m % k);
      continue;
    }
    int tot = 0;
    now[++tot] = arr[1];
    nowcnt[tot] = 1;
    for (int i = 2; i <= n; i++) {
      now[++tot] = arr[i];
      if (now[tot] == now[tot - 1])
        nowcnt[tot] = nowcnt[tot - 1] + 1;
      else
        nowcnt[tot] = 1;
      if (nowcnt[tot] == k) tot -= k;
    }
    int L = 1, R = tot, t = 0;
    int ride = 0;
    while (now[L] == now[R] && L < R) {
      int l = L, r = R, cnt = 0;
      while (now[l] == now[L] && l < r && cnt < k) {
        cnt++;
        l++;
      }
      while (now[r] == now[L] && l < r && cnt < k) {
        cnt++;
        r--;
      }
      if (cnt == k) {
        L = l;
        R = r;
        t += k;
      } else
        break;
    }
    single_color = true;
    long long ans = 0;
    for (int i = L + 1; i <= R; i++)
      if (now[i] != now[i - 1]) {
        single_color = false;
        break;
      }
    if (single_color) {
      if ((long long)m * (R - L + 1) % k)
        ans = (long long)m * (R - L + 1) % k + t;
      else
        ans = 0;
    } else
      ans = (long long)m * (R - L + 1) + t;
    printf("%lld\n", ans);
  }
}
