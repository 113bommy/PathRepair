#include <bits/stdc++.h>
using namespace std;
pair<int, int> p[100005];
long long acum[100005], ans[100005];
int id[100005];
bool comp(int x, int y) { return p[x].first < p[y].first; }
int main() {
  int n, k;
  scanf("%d%d", &n, &k);
  for (int i = 0; i < n; i++) scanf("%d", &p[i].first);
  for (int i = 0; i < n; i++) scanf("%d", &p[i].second), id[i] = i;
  sort(id, id + n, comp);
  priority_queue<int> Q;
  int best;
  long long sum = 0;
  for (int i = 0, j; i < n; i++) {
    j = id[i];
    if (Q.size() < k)
      Q.push(-p[j].second), sum += p[j].second;
    else {
      if (Q.size() > 0) {
        best = -Q.top();
        if (best < p[j].second) {
          sum -= best;
          sum += p[j].second;
          Q.pop();
          Q.push(-p[j].second);
        }
      }
    }
    acum[i] = sum;
  }
  for (int i = 0, j = 0; i < n; i++) {
    while (j < n && p[id[j]].first < p[id[i]].first) j++;
    ans[id[i]] = acum[j - 1] + p[id[i]].second;
  }
  for (int i = 0; i < n; i++) {
    if (i) printf(" ");
    printf("%I64d", ans[i]);
  }
}
