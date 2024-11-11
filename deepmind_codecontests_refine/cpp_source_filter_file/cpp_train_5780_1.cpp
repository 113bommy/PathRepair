#include <bits/stdc++.h>
using namespace std;
const int MAX_N = 1e5 + 42;
struct Edge {
  int len;
  bool included;
  int ind;
};
bool operator<(Edge u, Edge v) {
  if (u.len != v.len) {
    return u.len < v.len;
  } else {
    return u.included > v.included;
  }
}
pair<int, int> connects[MAX_N];
Edge edges[MAX_N];
int edgeCnt, vertCnt;
void input() {
  scanf("%i %i", &vertCnt, &edgeCnt);
  for (int i = 0; i < edgeCnt; i++) {
    scanf("%i %i", &edges[i].len, &edges[i].included);
    edges[i].ind = i;
  }
  sort(edges, edges + edgeCnt);
}
int main() {
  input();
  int found = 0;
  int notFoundF = 2;
  int notFoundSec = 3;
  for (int i = 0; i < edgeCnt; i++) {
    if (edges[i].included) {
      connects[edges[i].ind] = make_pair(1, 2 + found);
      found++;
    } else {
      if (notFoundSec >= found + 2) {
        printf("-1\n");
        return 0;
      }
      connects[edges[i].ind] = make_pair(notFoundF, notFoundSec);
      notFoundF++;
      if (notFoundF + 1 >= notFoundSec) {
        notFoundSec++;
        notFoundF = 2;
      }
    }
  }
  for (int i = 0; i < edgeCnt; i++) {
    printf("%i %i\n", connects[i].first, connects[i].second);
  }
}
