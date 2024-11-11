#include <bits/stdc++.h>
using namespace std;
const int N = 1010;
int n;
int ans[N];
int main() {
  memset(ans, 0x3f3f, sizeof(ans));
  cin >> n;
  for (int i = 0; i < 10; ++i)
    for (int t = 0; t < 2; ++t) {
      vector<int> v;
      for (int j = 1; j <= n; ++j)
        if (((j >> i) & 1) == t) v.push_back(j);
      if (v.empty()) continue;
      printf("%d\n", v.size());
      for (int j = 0; j < v.size(); ++j) printf("%d ", v[j]);
      puts("");
      fflush(stdout);
      for (int j = 1; j <= n; ++j) {
        int x;
        scanf("%d", &x);
        if (((j >> i) & 1) == t ^ 1) ans[j] = min(ans[j], x);
      }
    }
  puts("-1");
  for (int i = 1; i <= n; ++i) printf("%d ", ans[i] == 0x3f3f3f3f ? 0 : ans[i]);
  return 0;
}
