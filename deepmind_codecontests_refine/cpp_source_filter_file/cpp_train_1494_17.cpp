#include <bits/stdc++.h>
using namespace std;
const int maxN(1e5 + 10);
typedef int i_N[maxN];
int N, M, K;
i_N A;
vector<int> pos[maxN];
int main() {
  scanf("%d %d %d\n", &N, &M, &K);
  for (int i = 0; i < N; i++) scanf("%d ", A + i), pos[A[i]].push_back(i);
  int ans(0);
  for (int color = 1; color <= M; color++) {
    for (int l = 0, r = 0; l < (int)pos[color].size(); l++) {
      while (r < (int)pos[color].size() &&
             (pos[color][r] - pos[color][l]) - (r - l) <= K)
        r++;
      ans = max(ans, r - l);
    }
  }
  cout << ans;
}
