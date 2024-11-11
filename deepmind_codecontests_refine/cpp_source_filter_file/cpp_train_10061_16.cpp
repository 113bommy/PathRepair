#include <bits/stdc++.h>
using namespace std;
const int N = 1e6 + 1;
vector<int> p[N];
int main() {
  for (int i = 2; i < N; ++i) {
    if (p[i].empty()) {
      for (int j = i + i; j < N; j += i) {
        p[j].emplace_back(i);
      }
    }
  }
  int n;
  scanf("%d", &n);
  int ans = 1 << 20;
  for (int i = n - p[n].back() - 1; i <= n; ++i) {
    if (p[i].empty()) {
      continue;
    }
    ans = min(ans, i - p[i].back() + 1);
  }
  printf("%d\n", ans);
  return 0;
}
