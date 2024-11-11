#include <bits/stdc++.h>
using namespace std;
const int MAXN = 1010;
const int MAXM = 1e5 + 10;
struct query {
  int rt;
  int s, t;
  int i;
};
int N, M, Q;
int A[MAXM], B[MAXM];
vector<query> qu[MAXM];
bool ans[MAXM];
int dist[MAXN][MAXN];
int main() {
  scanf("%d %d %d", &N, &M, &Q);
  for (int i = 1; i <= M; i++) {
    scanf("%d %d", &A[i], &B[i]);
  }
  for (int i = 0; i < Q; i++) {
    int lt, rt, s, t;
    scanf("%d %d %d %d", &lt, &rt, &s, &t);
    qu[lt].push_back({rt, s, t, i});
  }
  for (int i = 1; i <= N; i++) {
    for (int j = 1; j < i; j++) {
      dist[i][j] = dist[j][i] = 1e8;
    }
  }
  for (int i = M; i > 0; i--) {
    for (int j = 1; j <= N; j++) {
      int d = min(dist[A[i]][j], dist[B[i]][j]);
      if (j != B[i]) {
        dist[A[i]][j] = d;
      }
      if (j != A[i]) {
        dist[B[i]][j] = d;
      }
    }
    dist[A[i]][B[i]] = dist[B[i]][A[i]] = i;
    for (query q : qu[i]) {
      ans[q.i] = (dist[q.s][q.t] <= q.rt);
    }
  }
  for (int i = 0; i < Q; i++) {
    puts(ans[i] ? "Yes" : "No");
  }
}
