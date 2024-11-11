#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const int maxn = 1e3 + 5;
bool used[maxn];
int n, k, a, b, c, d;
int main() {
  scanf("%d %d", &n, &k);
  scanf("%d %d %d %d", &a, &b, &c, &d);
  if (n <= 4 or k < n + 1) {
    puts("-1");
    return 0;
  }
  used[a] = used[b] = used[c] = used[d] = true;
  vector<int> path = {a, c};
  for (int i = 1; i <= n; i++)
    if (!used[i]) path.emplace_back(i);
  path.insert(path.end(), {d, b});
  for (int i = 0; i < n; i++) printf("%d%c", path[i], " \n"[i + 1 == n]);
  printf("%d %d ", path[1], path[0]);
  for (int i = 2; i < n - 2; i++) printf("%d ", path[i]);
  printf("%d %d\n", path[n - 1], path[n - 2]);
  return 0;
}
