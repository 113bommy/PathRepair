#include <bits/stdc++.h>
using namespace std;
const int N = 2e4 + 4;
int n, k1, k2, s1[N], x, s2[N], v[N], u[N], c1[N], c2[N];
queue<pair<pair<int, int>, int> > q;
int main() {
  scanf("%d%d", &n, &k1);
  for (int i = 0; i < k1; ++i) {
    scanf("%d", s1 + i);
    int k = n - s1[i];
    u[k] = 1;
    q.push({{0, 1}, k});
  }
  scanf("%d", &k2);
  for (int i = 0; i < k2; ++i) {
    scanf("%d", s2 + i);
    int k = n - s2[i];
    v[k] = 1;
    q.push({{1, 1}, k});
  }
  while (!q.empty()) {
    int x = q.front().first.first;
    int rst = q.front().first.second;
    int i = q.front().second;
    q.pop();
    int k = !x ? k2 : k1;
    int *c = !x ? c2 : c1;
    int *s = !x ? s2 : s1;
    int *r = !x ? v : u;
    if (rst)
      for (int j = 0; j < k; ++j) {
        int idx = (n + i - s[j]) % n;
        c[idx]++;
        if (c[idx] == k and idx) {
          r[idx] = -1;
          q.push({{!x, 0}, idx});
        }
      }
    if (!rst)
      for (int j = 0; j < k; ++j) {
        int idx = (n + i - s[j]) % n;
        if (!r[idx] and idx) {
          r[idx] = 1;
          q.push({{!x, 1}, idx});
        }
      }
  }
  for (int i = 1; i < n; ++i) {
    printf("%s ", !u[i] ? "Loop" : u[i] < 0 ? "Loose" : "Win");
  }
  printf("\n");
  for (int i = 1; i < n; ++i) {
    printf("%s ", !v[i] ? "Loop" : v[i] < 0 ? "Loose" : "Win");
  }
  printf("\n");
  return 0;
}
