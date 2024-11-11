#include <bits/stdc++.h>
using namespace std;
int R;
int C[59];
int A[59][59], T[59][59];
pair<int, int> B[2509];
vector<pair<pair<int, int>, pair<int, int> > > cmd;
int main() {
  int s = 0;
  scanf("%d", &R);
  for (int r = 1; r <= R; r++) scanf("%d", C + r), s += C[r];
  for (int r = 1; r <= R; r++)
    for (int v = 0, c = 1; c <= C[r]; c++)
      scanf("%d", &v), B[v] = make_pair(r, c), A[r][c] = v;
  for (int r = R; r >= 1; r--) {
    for (int c = C[r]; c >= 1; c--, s--) {
      if (r == B[s].first && c == B[s].second) continue;
      cmd.push_back(make_pair(make_pair(r, c), B[s]));
      int ARC = A[r][c];
      swap(A[r][c], A[B[s].first][B[s].second]);
      B[ARC] = B[s];
      B[s].first = r, B[s].second = c;
    }
  }
  printf("%d\n", cmd.size());
  for (int i = 0; i < cmd.size(); i++)
    printf("%d %d %d %d\n", cmd[i].first.first, cmd[i].first.second,
           cmd[i].second.first, cmd[i].second.second);
  return 0;
}
