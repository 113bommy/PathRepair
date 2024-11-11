#include <bits/stdc++.h>
using namespace std;
vector<int> x, edge[100005];
int main() {
  int n, m;
  scanf("%d%d", &n, &m);
  for (int i = 0; i < m; i++) {
    int a, b;
    scanf("%d%d", &a, &b);
    edge[a].push_back(b);
    edge[b].push_back(a);
  }
  for (int i = 1; i <= n; i++) x.push_back(i);
  for (int t = 0; t < 1000; t++) {
    int fail = 0;
    random_shuffle(x.begin(), x.end());
    for (int i = 0; i < m; i++)
      if (find(edge[x[i]].begin(), edge[x[i]].end(), x[(i + 1) % n]) !=
          edge[x[i]].end())
        fail = 1;
    if (!fail) {
      for (int i = 0; i < m; i++) printf("%d %d\n", x[i], x[(i + 1) % n]);
      return 0;
    }
  }
  puts("-1");
  return 0;
}
