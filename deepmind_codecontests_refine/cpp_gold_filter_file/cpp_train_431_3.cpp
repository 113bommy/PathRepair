#include <bits/stdc++.h>
using namespace std;
int main() {
  int Q;
  scanf("%d", &Q);
  while (Q--) {
    int N, M;
    scanf("%d%d", &N, &M);
    std::vector<std::pair<int, int> > edges(M);
    for (int i = 0; i < M; ++i) {
      scanf("%d%d", &edges[i].first, &edges[i].second);
    }
    std::unordered_set<int> sIn;
    std::vector<int> match, ind;
    for (int i = 0; i < M; ++i) {
      if (sIn.count(edges[i].first)) continue;
      if (sIn.count(edges[i].second)) continue;
      match.push_back(i + 1);
      sIn.insert(edges[i].first);
      sIn.insert(edges[i].second);
    }
    if (match.size() >= N) {
      printf("Matching\n");
      for (int i = 0; i < N; ++i) printf("%d ", match[i]);
      printf("\n");
    } else {
      printf("IndSet\n");
      int cnt = 0;
      for (int i = 1; i <= 3 * N; ++i) {
        if (sIn.count(i)) continue;
        cnt++;
        printf("%d ", i);
        if (cnt == N) break;
      }
      printf("\n");
    }
  }
}
