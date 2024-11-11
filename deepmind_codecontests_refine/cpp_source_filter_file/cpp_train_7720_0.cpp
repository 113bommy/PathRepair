#include <bits/stdc++.h>
using namespace std;
const int M = 1e6 + 10;
set<int> se;
int a[M], b[M];
int main() {
  int T;
  scanf("%d", &T);
  while (T--) {
    int n;
    se.clear();
    scanf("%d", &n);
    for (int i = 1; i <= n; i++) {
      int x;
      scanf("%d", &x);
      se.insert(x);
    }
    int num = 0;
    for (auto v : se) {
      b[++num] = v;
    }
    int ans = 0;
    for (int i = num; i >= 1; i--) {
      ans = max(ans, b[i]);
      for (int j = num; j > i; j--) {
        if (b[j] % b[i] != 0) {
          ans = max(ans, b[i] + b[j]);
          for (int k = j - 1; k > i; k--) {
            if (b[j] % b[k] != 0 && b[i] % b[k] != 0) {
              ans = max(ans, b[i] + b[j] + b[k]);
              break;
            }
          }
          break;
        }
      }
    }
    printf("%d\n", ans);
  }
  return 0;
}
