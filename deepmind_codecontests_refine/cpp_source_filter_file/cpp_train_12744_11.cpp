#include <bits/stdc++.h>
using namespace std;
const int nmax = 5010;
char A[nmax][nmax];
int D[nmax][nmax];
vector<int> V[nmax];
vector<int> T[nmax];
int N, M, out;
int main() {
  scanf("%d%d", &N, &M);
  for (int i = 1; i <= N; ++i) scanf("%c", A[i] + 1);
  int mx = 0;
  for (int i = 1; i <= N; ++i)
    for (int j = M; j >= 1; --j) {
      D[i][j] = A[i][j] == '1' ? D[i][j + 1] + 1 : 0;
      V[D[i][j]].push_back(j);
      mx = max(mx, D[i][j]);
    }
  for (int i = mx; i > 0; --i)
    for (size_t j = 0; j < V[i].size(); ++j) T[V[i][j]].push_back(i);
  for (int i = 1; i <= M; ++i)
    for (size_t j = 0; j < T[i].size(); ++j)
      out = max(out, T[i][j] * int(j + 1));
  printf("%d\n", out);
}
