#include <bits/stdc++.h>
using namespace std;
const int maxn = 1e6 + 5;
int d[maxn], b[maxn];
int main() {
  int n, a;
  cin >> n;
  memset(d, 0, sizeof(d));
  for (int i = 0; i < n; i++) scanf("%d ", &a), scanf("%d", &b[a]);
  if (b[0] > 0) d[0] = 1;
  int ans = 0;
  for (int i = 1; i < maxn; i++) {
    if (b[i] == 0)
      d[i] = d[i - 1];
    else {
      if (b[i] > i)
        d[i] = 1;
      else
        d[i] = d[i - b[i] - 1] + 1;
    }
    if (d[i] > ans) ans = d[i];
  }
  cout << n - ans << endl;
}
