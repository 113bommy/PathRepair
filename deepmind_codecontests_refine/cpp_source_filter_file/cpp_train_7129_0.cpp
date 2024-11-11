#include <bits/stdc++.h>
using namespace std;
const int MAXN = 1005;
int N, M, A, B, dist[MAXN], comp[MAXN], far[MAXN], C, res;
int Q[MAXN], H, T;
vector<int> adj[MAXN];
int main() {
  cin >> N >> M;
  for (int i = 0; i < M; i++) {
    cin >> A >> B;
    A -= 1, B -= 1;
    adj[A].push_back(B);
    adj[B].push_back(A);
  }
  memset(comp, -1, sizeof(comp));
  for (int i = 0; i < N; i++) {
    int f = 0;
    memset(dist, -1, sizeof(dist));
    H = T = 0;
    dist[i] = 0;
    Q[T++] = i;
    while (H < T) {
      int v = Q[H++];
      for (int n : adj[v]) {
        if (dist[n] < 0) {
          if (comp[n] >= 0) comp[i] = n;
          dist[n] = dist[v] + 1;
          Q[T++] = n;
          f = max(f, dist[n]);
        } else if (dist[n] % 2 == dist[v] % 2) {
          cout << -1 << '\n';
          return 0;
        }
      }
    }
    if (comp[i] < 0) comp[i] = C++;
    far[comp[i]] = max(far[comp[i]], f);
  }
  for (int i = 0; i < C; i++) {
    res += far[i];
  }
  cout << res << '\n';
}
