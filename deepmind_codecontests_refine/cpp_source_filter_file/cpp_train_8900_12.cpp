#include <bits/stdc++.h>
using namespace std;
const int maxn = 1e5 + 10;
int h[maxn], preMax[maxn], suffMin[maxn];
int main() {
  int n;
  scanf("%d", &n);
  for (int i = 1; i <= n; i++) scanf("%d", &h[i]);
  preMax[0] = 0;
  suffMin[n + 1] = 1e9 + 10;
  for (int i = 1; i <= n; i++) {
    preMax[i] = max(preMax[i], h[i]);
  }
  for (int i = n; i >= 1; i--) {
    suffMin[i] = min(suffMin[i + 1], h[i]);
  }
  int ret = 0;
  for (int i = 1; i <= n; i++) {
    if (preMax[i] < suffMin[i + 1]) {
      ret++;
    }
  }
  cout << ret << endl;
  return 0;
}
