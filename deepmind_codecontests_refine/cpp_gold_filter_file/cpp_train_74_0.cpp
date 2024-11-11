#include <bits/stdc++.h>
#pragma comment(linker, "/STACK:102400000,102400000")
using namespace std;
const int N = 1e6 + 10;
int n, m, k;
bool des[N];
int l[N], a[N];
int main() {
  cin >> n >> m >> k;
  for (int i = 1; i <= m; i++) {
    int t;
    scanf("%d", &t);
    des[t] = true;
  }
  for (int i = 1; i <= k; i++) scanf("%d", &a[i]);
  if (des[0]) {
    printf("-1\n");
    return 0;
  }
  l[0] = 0;
  for (int i = 1; i < n; i++)
    if (des[i - 1])
      l[i] = l[i - 1];
    else
      l[i] = i;
  long long ans = 1ll << 62;
  for (int i = 1; i <= k; i++) {
    int cur = 0;
    long long tmp = 0;
    while (true) {
      tmp += a[i];
      cur += i;
      if (cur >= n) break;
      if (des[cur]) {
        if (cur - l[cur] + 1 >= i) {
          tmp = 1ll << 62;
          break;
        } else {
          cur = l[cur] - 1;
        }
      }
    }
    ans = min(ans, tmp);
  }
  if (ans == 1ll << 62)
    puts("-1");
  else
    cout << ans << endl;
}
