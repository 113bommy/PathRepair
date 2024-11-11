#include <bits/stdc++.h>
using namespace std;
int N, M;
int P;
vector<int> Adj[500005];
char Str[500005];
int C[500005];
int V, H;
int LIdx = 0;
int ST[500005], EN[500005];
vector<int> Idxes[500005];
vector<int> Depth[500005];
vector<vector<int> > Alpha[500005];
void DFS(int V, int D) {
  Depth[D].push_back(V);
  Idxes[D].push_back(LIdx);
  ST[V] = LIdx++;
  for (int i = 0; i < Adj[V].size(); i++) DFS(Adj[V][i], D + 1);
  EN[V] = LIdx - 1;
}
bool Solve(int D, int S, int E) {
  int SP = lower_bound(Idxes[D].begin(), Idxes[D].end(), S) - Idxes[D].begin();
  int EP = upper_bound(Idxes[D].begin(), Idxes[D].end(), E) - Idxes[D].begin();
  int Diff;
  bool Odd = 0;
  for (int i = 0; i < 26; i++) {
    Diff = Alpha[D][EP][i] - Alpha[D][SP][i];
    if ((Diff & 1) && Odd)
      return 0;
    else if (Diff & 1)
      Odd = 1;
  }
  return 1;
}
int main() {
  scanf("%d%d", &N, &M);
  for (int i = 2; i <= N; i++) {
    scanf("%d", &P);
    Adj[P].push_back(i);
  }
  scanf("%s", Str);
  for (int i = 0; i < N; i++) C[i + 1] = (Str[i] - 'a');
  DFS(1, 1);
  vector<int> New(26);
  for (int i = 1; i <= N; i++) {
    for (int j = 0; j < 26; j++) New[j] = 0;
    Alpha[i].push_back(New);
    for (int j = 0; j < Depth[i].size(); j++) {
      New[C[Depth[i][j]]]++;
      Alpha[i].push_back(New);
    }
  }
  while (M--) {
    scanf("%d%d", &V, &H);
    printf(Solve(H, ST[V], EN[V]) ? "Yes\n" : "No\n");
  }
}
