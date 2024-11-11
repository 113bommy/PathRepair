#include <bits/stdc++.h>
using namespace std;
const int inf = 1e9;
void solve() {
  int n = 250;
  vector<int> a(n);
  for (int i = 0; i < n; ++i) {
    scanf("%d", &a[i]);
  }
  for (int i = 0; i < 2e3 + 2; ++i) {
    int cnt = 0;
    int l = i - i / 2;
    int r = i + i / 2;
    for (int j = 0; j < n; ++j) {
      if (l <= a[j] && a[j] <= r) ++cnt;
    }
    if ((double)cnt / (double)n >= 0.95) {
      printf("poisson\n");
      return;
    }
  }
  printf("uniform\n");
}
int main() {
  int t;
  scanf("%d", &t);
  while (t--) solve();
  return 0;
}
