#include <bits/stdc++.h>
using namespace std;
const int inft = 1000000009;
const int MAXN = 1006;
bool t[MAXN][MAXN];
vector<pair<int, int> > A, B, ANS;
void get(int p, int k, int mode = 0) {
  if (p >= k - 1) return;
  vector<int> C;
  for (int i = p; i <= k; i++)
    if (t[1][i]) C.push_back(i);
  if (C.size() == 2) {
    int w = -1;
    for (int i = p + 1; i < k; i++)
      if (t[p][i] && t[k][i]) {
        assert(w == -1);
        w = i;
        break;
      }
    if (mode)
      ANS.push_back(pair<int, int>(1, w));
    else
      ANS.push_back(pair<int, int>(p, k));
    t[p][k] = t[k][p] = 0;
    t[1][w] = t[w][1] = 1;
    get(p, w, mode);
    get(w, k, mode);
  } else {
    for (int i = 0; i < (C.size() - 1); ++i) get(C[i], C[i + 1], mode);
  }
}
void solve() {
  int n;
  scanf("%d", &n);
  for (int i = 0; i < (n - 3); ++i) {
    int a, b;
    scanf("%d%d", &a, &b);
    t[a][b] = t[b][a] = 1;
  }
  for (int i = 0; i < (n - 1); ++i) t[i + 1][i + 2] = t[i + 2][i + 1] = 1;
  t[1][n] = t[n][1] = 1;
  get(2, n);
  swap(A, ANS);
  ANS.clear();
  for (int i = 0; i < (n + 1); ++i)
    for (int j = 0; j < (n + 1); ++j) t[i][j] = 0;
  for (int i = 0; i < (n - 3); ++i) {
    int a, b;
    scanf("%d%d", &a, &b);
    t[a][b] = t[b][a] = 1;
  }
  for (int i = 0; i < (n - 1); ++i) t[i + 1][i + 2] = t[i + 2][i + 1] = 1;
  t[1][n] = t[n][1] = 1;
  get(2, n, 1);
  swap(B, ANS);
  reverse((B).begin(), (B).end());
  printf("%d\n", A.size() + B.size());
  for (typeof((A).begin()) it = (A).begin(); it != (A).end(); ++it)
    printf("%d %d\n", it->first, it->second);
  for (typeof((B).begin()) it = (B).begin(); it != (B).end(); ++it)
    printf("%d %d\n", it->first, it->second);
}
int main() {
  int t = 1;
  for (int i = 0; i < (t); ++i) solve();
  return 0;
}
