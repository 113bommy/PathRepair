#include <bits/stdc++.h>
using namespace std;
int main() {
  int t;
  scanf("%d", &t);
  while (t--) {
    int n, m, k;
    scanf("%d%d%d", &n, &m, &k);
    vector<int> h(n, 0);
    for (int i = 0; i < n; ++i) {
      scanf("%d", &h[i]);
    }
    int f = 1;
    for (int i = 0; i < n - 1; ++i) {
      m -= max(0, h[i + 1] - h[i] - k);
      if (m < 0) {
        f = 0;
        break;
      }
      m += max(0, h[i] - max(0, h[i + 1] - k));
    }
    puts(f ? "YES" : "NO");
  }
}
