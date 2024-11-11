#include <bits/stdc++.h>
int votes[101];
int main() {
  int n, m;
  scanf("%d%d", &n, &m);
  for (int i = 0; i < m; ++i) {
    int idx = -1;
    int vote, max_vote = 0;
    for (int j = 1; j <= n; ++j) {
      scanf("%d", &vote);
      if (max_vote < vote) {
        idx = j;
        max_vote = vote;
      }
    }
    votes[idx]++;
  }
  int max_vote = 0;
  int max_idx = 1;
  for (int i = 1; i <= n; ++i) {
    if (max_vote < votes[i]) {
      max_idx = i;
      max_vote = votes[i];
    }
  }
  printf("%d\n", max_idx);
  return 0;
}
