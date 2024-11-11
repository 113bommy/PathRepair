#include <bits/stdc++.h>
using namespace std;
void printv(vector<int> arr, int n) {
  for (int i = 0; i < n; ++i) printf("%d ", arr[i]);
  cout << endl;
}
void print(int arr[], int n) {
  for (int i = 0; i < n; ++i) printf("%d ", arr[i]);
  cout << endl;
}
bool isPrime(int n) {
  bool flag = 1;
  for (int i = 2; i <= sqrt(n); ++i) {
    if (n % i == 0) {
      flag = 0;
      break;
    }
  }
  return (flag ? 1 : 0);
}
const int naX = 1e5 + 5;
vector<int> g[naX];
int dist, orig_dist, node;
int n, a, b, da, db;
void dfs(int c, int par, int d) {
  if (d > dist) {
    dist = d;
    node = c;
  }
  for (auto &it : g[c]) {
    if (it == par) continue;
    dfs(it, c, d + 1);
  }
}
void dfs2(int c, int par, int d) {
  if (c == b) orig_dist = d;
  for (auto &it : g[c]) {
    if (it == par) continue;
    dfs2(it, c, d + 1);
  }
}
void test_case() {
  scanf("%d%d%d%d%d", &n, &a, &b, &da, &db);
  for (int i = 1; i <= n; ++i) g[i].clear();
  for (int i = 1; i < n; ++i) {
    int x, y;
    scanf("%d%d", &x, &y);
    g[x].push_back(y);
    g[y].push_back(x);
  }
  dist = -1;
  dfs(1, 1, 0);
  dist = -1;
  dfs(node, node, 0);
  db = min(dist, db);
  dfs2(a, a, 0);
  if (db > 2 * da && orig_dist > da) {
    printf("Bob\n");
  } else {
    printf("Alice\n");
  }
}
int main() {
  int t = 1;
  scanf("%d", &t);
  while (t--) {
    test_case();
  }
  return 0;
}
