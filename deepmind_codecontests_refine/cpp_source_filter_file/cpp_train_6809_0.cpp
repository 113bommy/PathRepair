#include <bits/stdc++.h>
using namespace std;
int n, m, k;
bool marked[305];
int a, b;
vector<pair<int, int> > edges;
int main() {
  scanf("%d %d %d", &n, &m, &k);
  scanf("%d %d", &a, &b);
  marked[a] = marked[b] = true;
  for (int i = 2; i < k; i++) {
    int t = scanf("%d", &t);
    marked[t] = true;
  }
  if (k == n) {
    printf("-1\n");
    return 0;
  }
  int center;
  for (int i = 1; i <= n; i++) {
    if (!marked[i]) {
      center = i;
      break;
    }
  }
  for (int i = 1; i <= n; i++) {
    if (i != a && i != b) {
      edges.push_back(make_pair(a, i));
    }
  }
  edges.push_back(make_pair(b, center));
  if (edges.size() < m) {
    for (int i = 1; i <= n - 1; i++) {
      for (int j = i + 1; j <= n; j++) {
        if (i != a && j != a) {
          if (i == b || j == b) {
            if (i != center && j != center && !(marked[i] && marked[j])) {
              edges.push_back(make_pair(i, j));
            }
          } else {
            edges.push_back(make_pair(i, j));
          }
          if (edges.size() == m) break;
        }
      }
      if (edges.size() == m) break;
    }
  }
  if (edges.size() < m) {
    printf("-1\n");
    return 0;
  } else {
    for (int i = 0; i < edges.size(); i++) {
      printf("%d %d\n", edges[i].first, edges[i].second);
    }
  }
  return 0;
}
