#include <bits/stdc++.h>
using namespace std;
int M, N;
struct Edge {
  int U;
  int V;
} Edge[499501];
int main() {
  int i, j, k;
  int cnt = 0;
  cin >> N >> M;
  for (i = 1; i <= M; i++) {
    for (j = 1; j <= N; j++) {
      if (cnt >= N * (N - 1) / 2) {
        cout << -1 << endl;
        return 0;
      }
      Edge[cnt].U = j;
      Edge[cnt].V = ((j + i) % N == 0) ? N : (j + i) % N;
      cnt++;
    }
  }
  cout << cnt << endl;
  for (i = 0; i < cnt; i++) printf("%d %d\n", Edge[i].U, Edge[i].V);
}
