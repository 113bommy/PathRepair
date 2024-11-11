#include <bits/stdc++.h>
using namespace std;
const int N = 1e5 + 100;
vector<int> G[N];
int main() {
  int n, k, m;
  cin >> n >> k >> m;
  for (int i = 1; i <= n; i++) {
    int now;
    scanf("%d", &now);
    G[now % m].push_back(now);
  }
  for (int i = 0; i < m; i++) {
    if (G[i].size() >= k) {
      puts("YES");
      for (int j = 0; j < k; j++) {
        printf("%d%c", G[i][j], j == k - 1 ? '\n' : ' ');
      }
      return 0;
    }
  }
  puts("NO");
  return 0;
}
