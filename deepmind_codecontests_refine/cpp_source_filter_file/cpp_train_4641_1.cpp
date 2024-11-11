#include <bits/stdc++.h>
using namespace std;
const int N = 200000 + 5;
int n, m, K;
int a[N], b[N];
int far[N];
int q[N];
vector<int> v[N];
set<int> se;
set<int>::iterator it;
int main() {
  scanf("%d", &n);
  for (int i = 1; i <= n; i++) {
    scanf("%d%d", &a[i], &b[i]);
    v[a[i]].push_back(i);
    far[a[i]] = i;
  }
  for (int i = 1; i <= n; i++) {
    if (far[i] == 0) continue;
    se.insert(far[i]);
  }
  scanf("%d", &m);
  int f1, f2;
  while (m--) {
    scanf("%d", &K);
    for (int i = 0; i < K; i++) {
      scanf("%d", &q[i]);
    }
    for (int i = 0; i < K; i++) {
      if (far[q[i]] == 0) continue;
      se.erase(far[q[i]]);
    }
    if (se.size() == 0) {
      printf("0 0\n");
    } else if (se.size() == 1) {
      f1 = *se.begin();
      printf("%d %d\n", a[f1], b[v[a[f1]][0]]);
    } else {
      it = se.end();
      it--;
      f1 = *it;
      it--;
      f2 = *it;
      printf("%d %d\n", a[f1],
             b[v[a[f1]][lower_bound(v[a[f1]].begin(), v[a[f1]].end(), far[f2]) -
                        v[a[f1]].begin()]]);
    }
    for (int i = 0; i < K; i++) {
      if (far[q[i]] == 0) continue;
      se.insert(far[q[i]]);
    }
  }
}
