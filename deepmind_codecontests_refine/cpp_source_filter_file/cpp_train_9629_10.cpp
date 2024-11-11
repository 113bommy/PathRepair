#include <bits/stdc++.h>
using namespace std;
const int N = 500005;
int n, m, arr[N], startTime[N], endTime[N], dfsN;
bool charSum[N][26];
char nodes[N];
vector<int> adjL[N], H[N];
void DFS(int node, int depth) {
  arr[++dfsN] = node, H[depth].push_back(dfsN), startTime[node] = dfsN;
  for (int ch : adjL[node]) DFS(ch, depth + 1);
  endTime[node] = dfsN;
}
int main() {
  scanf("%d%d", &n, &m);
  for (int i = (2); i <= (int)(n); ++i) {
    int p;
    scanf("%d", &p);
    adjL[p].push_back(i);
  }
  scanf("%s", nodes + 1);
  DFS(1, 1);
  for (int i = (1); i <= (int)(n); ++i) charSum[i][nodes[i] - 'a'] = true;
  for (int i = (1); i <= (int)(n); ++i)
    for (int j = (1); j <= (int)(((int)(H[i]).size()) - 1); ++j)
      for (int a = (0); a <= (int)(25); ++a)
        charSum[arr[H[i][j]]][a] ^= charSum[arr[H[i][j - 1]]][a];
  while (m--) {
    int v, h;
    scanf("%d%d", &h, &v);
    int ans = 0;
    int l = (int)(lower_bound(H[h].begin(), H[h].end(), startTime[v]) -
                  H[h].begin());
    int r =
        (int)(lower_bound(H[h].begin(), H[h].end(), endTime[v]) - H[h].begin());
    if (r && (r == ((int)(H[h]).size()) || H[h][r] > endTime[v])) --r;
    if (r < ((int)(H[h]).size())) {
      if (l) {
        for (int a = (0); a <= (int)(25); ++a)
          ans += charSum[arr[H[h][l - 1]]][a] ^ charSum[arr[H[h][r]]][a];
      } else {
        for (int a = (0); a <= (int)(25); ++a) ans += charSum[arr[H[h][r]]][a];
      }
    }
    if (ans > 1)
      printf("NO\n");
    else
      printf("YES\n");
  }
}
