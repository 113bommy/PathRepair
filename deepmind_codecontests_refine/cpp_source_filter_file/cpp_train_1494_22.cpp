#include <bits/stdc++.h>
using namespace std;
const int MAX_N = 200005;
int N, M, K;
vector<int> pos[MAX_N];
vector<int> delta[MAX_N];
int main() {
  scanf("%d %d %d", &N, &M, &K);
  for (int i = 0; i < N; i++) {
    int c;
    scanf("%d", &c);
    c--;
    pos[c].push_back(i);
  }
  int best = 0;
  for (int i = 0; i < M; i++) {
    ;
    for (int j = 1; j < pos[i].size(); j++) {
      delta[i].push_back(pos[i][j] - pos[i][j - 1] - 1);
      ;
    }
    int upto = 0;
    int cur = 0;
    for (int j = 0; j < delta[i].size(); j++) {
      while (upto < delta[i].size() && cur + delta[i][upto] <= K) {
        cur += delta[i][upto];
        upto++;
      }
      best = max(best, upto - j + 1);
      cur -= delta[i][j];
    }
  }
  printf("%d\n", best);
  return 0;
}
