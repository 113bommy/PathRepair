#include <bits/stdc++.h>
using namespace std;
vector<int> V[100005];
int main() {
  int N, M, K, ans = 0;
  scanf("%d%d%d", &N, &M, &K);
  for (int i = 1; i <= N; ++i) {
    int c;
    scanf("%d", &c);
    V[c].push_back(i);
  }
  for (int c = 1; c <= M; ++c) {
    int L = V[c].size(), rem = 0, st = 0;
    for (int j = 1; j < L; ++j) {
      rem += V[c][j] - V[c][j - 1] - 1;
      while (rem > K) {
        rem -= V[c][st + 1] - V[c][st] - 1;
        ++st;
      }
      ans = max(ans, j - st + 1);
    }
  }
  printf("%d\n", ans);
}
