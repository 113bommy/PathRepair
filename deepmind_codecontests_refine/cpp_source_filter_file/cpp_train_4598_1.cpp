#include <bits/stdc++.h>
using namespace std;
long long ans;
const int maxn = 1e6 + 10;
int n, x;
int a[maxn];
int minid[maxn], maxid[maxn];
int maxv[maxn], minv[maxn];
int main() {
  scanf("%d%d", &n, &x);
  for (int i = 1; i <= n; i++) {
    scanf("%d", a + i);
    maxid[a[i]] = i;
    maxv[i] = max(maxv[i - 1], a[i]);
  }
  minv[n + 1] = x + 1;
  for (int i = n; i >= 1; i--) {
    minid[a[i]] = i;
    minv[i] = min(minv[i + 1], a[i]);
  }
  int LOW = 1, HIGH = x + 1;
  for (int i = 1; i <= x; i++) {
    if (maxid[i] == 0) continue;
    if (maxv[maxid[i]] > i) LOW = i;
  }
  for (int i = 1; i <= LOW; i++) {
    LOW = max(LOW, i);
    if (maxid[i] == 0) {
      ans += (x - LOW + 1);
      continue;
    }
    ans += (x - LOW + 1);
    LOW = max(LOW, maxv[maxid[i]]);
    if (i > minv[minid[i]]) break;
  }
  cout << ans;
  return 0;
}
