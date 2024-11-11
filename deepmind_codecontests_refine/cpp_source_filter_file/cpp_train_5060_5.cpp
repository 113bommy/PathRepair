#include <bits/stdc++.h>
using namespace std;
const int maxn = 2e3 + 88;
set<int> ans;
int a[maxn], b[maxn];
int main() {
  int n, k, i, j;
  cin >> n >> k;
  for (i = 0; i < n; i++) cin >> a[i];
  for (i = 0; i < k; i++) cin >> b[i];
  sort(b, b + n);
  for (i = 1; i < n; i++) a[i] += a[i - 1];
  sort(a, a + n);
  for (i = 0; i < n; i++) {
    int x = b[0] - a[i];
    if (ans.count(x)) continue;
    int now = 1;
    bool is = true;
    for (j = i + 1; j < n && now < k; j++) {
      if (x + a[j] > b[now]) {
        is = false;
        break;
      }
      if (x + a[j] == b[now]) now++;
    }
    if (is && now == k) ans.insert(x);
  }
  cout << ans.size();
  return 0;
}
