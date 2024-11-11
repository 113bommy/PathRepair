#include <bits/stdc++.h>
using namespace std;
const int N = 1000010;
int n, m, k, arr[N], a, nxt[N], nj;
bool blocked[N];
int main() {
  scanf("%d%d%d", &n, &m, &k);
  for (int i = 0; i < m; i++) {
    scanf("%d", &a);
    blocked[a] = true;
  }
  nxt[0] = -1;
  for (int i = 1; i <= n; i++) {
    if (blocked[i - 1])
      nxt[i] = nxt[i - 1];
    else
      nxt[i] = i - 1;
  }
  for (int i = 1; i <= k; i++) scanf("%d", &arr[i]);
  long long ans = (long long)4e18, cur;
  for (int i = 1; i <= k; i++) {
    cur = 0;
    for (int j = 0; j < n;) {
      if (blocked[j]) {
        cur = (long long)4e18;
        break;
      }
      nj = j + i;
      if (nj < n && blocked[nj]) {
        nj = nxt[nj];
      }
      if (nj <= j) {
        cur = (long long)4e18;
        break;
      }
      cur += arr[i];
      j = nj;
    }
    ans = min(ans, cur);
  }
  if (ans >= (long long)3e18) ans = -1;
  cout << ans << endl;
  return 0;
}
