#include <bits/stdc++.h>
using namespace std;
pair<int, int> a[1000];
int b[1000];
vector<int> gr[1000];
bool used[1000];
bool cmp(pair<int, int> a, pair<int, int> b) { return a > b; }
int main() {
  int n, m;
  scanf("%d%d", &n, &m);
  for (int i = 0; i < (n); i++) {
    scanf("%d", &a[i].first);
    a[i].second = i;
    b[i] = a[i].first;
  }
  sort(a, a + n, cmp);
  int q, w;
  for (int i = 0; i < (m); i++) {
    scanf("%d%d", &q, &w);
    gr[q - 1].push_back(w - 1);
    gr[w - 1].push_back(q - 1);
  }
  long long res = 0;
  for (int i = 0; i < (n); i++) {
    for (int j = 0; j < (gr[a[i].second].size()); j++) {
      int u = gr[a[i].second][j];
      if (used[u]) continue;
      res += b[u];
    }
    used[a[i].second] = 1;
  }
  printf("%I64d", res);
  return 0;
}
