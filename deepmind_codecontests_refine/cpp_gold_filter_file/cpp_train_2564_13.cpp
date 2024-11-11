#include <bits/stdc++.h>
using namespace std;
int n;
vector<long long> p[2], q[2];
int main() {
  scanf("%d", &n);
  p[0].push_back(1LL);
  q[0].push_back(0LL);
  int x = 0;
  for (int k = 0; k < n; k++) {
    x ^= 1;
    p[x].clear();
    q[x].clear();
    p[x].push_back(0LL);
    for (int i = 0; i < p[x ^ 1].size(); i++)
      p[x].push_back(p[x ^ 1][i]), q[x].push_back(p[x ^ 1][i]);
    for (int i = 0; i < q[x ^ 1].size(); i++) p[x][i] ^= q[x ^ 1][i];
  }
  printf("%d\n", p[x].size() - 1);
  for (auto v : p[x]) printf("%lld ", v);
  printf("\n");
  printf("%d\n", q[x].size() - 1);
  for (auto v : q[x]) printf("%lld ", v);
  printf("\n");
  return 0;
}
