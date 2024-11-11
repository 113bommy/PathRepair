#include <bits/stdc++.h>
using namespace std;
const int N = 1e5 + 5;
int n;
vector<int> adj[N], one;
int cnt, x;
int main() {
  scanf("%d", &n);
  if (n == 1) {
    puts("Yes");
    printf("1\n1 1");
    return 0;
  }
  for (int i = 1, u, v; i < n; ++i) {
    scanf("%d%d", &u, &v);
    adj[u].push_back(v);
    adj[v].push_back(u);
  }
  for (int i = 1; i <= n; ++i) {
    if (adj[i].size() == 1)
      one.push_back(i);
    else if (adj[i].size() > 2)
      ++cnt, x = i;
  }
  if (cnt > 1) return puts("No");
  puts("Yes");
  printf("%d\n", (one.size() + 1) / 2);
  for (int i = 1; i < one.size(); i += 2) {
    printf("%d %d\n", one[i - 1], one[i]);
  }
  if (one.size() & 1) printf("%d %d\n", one.back(), x);
}
