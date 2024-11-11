#include <bits/stdc++.h>
using namespace std;
const int MaxA = 100 + 7;
int n;
pair<int, int> p[MaxA];
int main() {
  while (~scanf("%d", &n)) {
    for (int i = 0; i < n; i++) {
      scanf("%d%d", &p[i].first, &p[i].second);
    }
    sort(p, p + n);
    int pos = 0;
    while (pos < n && p[pos].first < 0) pos++;
    int b = n - pos, a = n - b;
    long long ans = 0;
    if (a > b) {
      for (int i = pos; i < n; i++) {
        ans += p[i].second;
      }
      b++;
      for (int i = pos - 1; b-- && i >= 0; i--) {
        ans += p[i].second;
      }
    } else {
      for (int i = pos - 1; i >= 0; i--) {
        ans += p[i].second;
      }
      a++;
      for (int i = pos; a-- && i >= 0; i++) {
        ans += p[i].second;
      }
    }
    printf("%I64d\n", ans);
  }
  return 0;
}
