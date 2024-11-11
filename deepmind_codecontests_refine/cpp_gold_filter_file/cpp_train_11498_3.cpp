#include <bits/stdc++.h>
using namespace std;
int N, M, C;
vector<pair<int, pair<int, int> > > V;
int A[505][505], R[505][505];
int main() {
  int x, y, t;
  scanf("%d %d", &N, &M);
  memset(A, 40, sizeof A);
  for (int i = 1; i <= M; i++) {
    scanf("%d %d %d", &x, &y, &t);
    A[x][y] = A[y][x] = t;
    V.push_back(make_pair(t, make_pair(x, y)));
  }
  for (int i = 1; i <= N; i++) A[i][i] = 0;
  for (int k = 1; k <= N; k++)
    for (int i = 1; i <= N; i++)
      for (int j = 1; j <= N; j++) A[i][j] = min(A[i][j], A[i][k] + A[k][j]);
  for (int i = 1; i <= N; i++)
    for (typeof(V.begin()) it = V.begin(); it != V.end(); it++) {
      if (A[i][it->second.first] + it->first == A[i][it->second.second])
        ++R[i][it->second.second];
      if (A[i][it->second.second] + it->first == A[i][it->second.first])
        ++R[i][it->second.first];
    }
  for (int i = 1; i <= N; i++)
    for (int j = i + 1; j <= N; j++) {
      int ans = 0;
      for (int k = 1; k <= N; k++)
        if (A[i][k] + A[k][j] == A[i][j]) ans += R[i][k];
      printf("%d ", ans);
    }
  cerr << "\nTime: " << (double)clock() / CLOCKS_PER_SEC << " seconds." << endl;
  return 0;
}
