#include <bits/stdc++.h>
using namespace std;
int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  int N;
  cin >> N;
  int C[N], A[N];
  for (int i = 0; i < N; ++i) cin >> C[i];
  for (int i = 0; i < N; ++i) cin >> A[i], --A[i];
  int V[N];
  for (int i = 0; i < N; ++i) V[i] = 0;
  int ans = 0;
  for (int i = 0; i < N; ++i)
    if (V[i] == 0) {
      stack<int> S;
      S.push(i);
      V[i] = 1;
      while (!S.empty()) {
        int u = S.top();
        int v = A[u];
        if (V[v] == 0) {
          S.push(v);
          V[v] = 1;
          continue;
        } else if (V[v] == 1) {
          int aux = C[v];
          while (S.top() != v) {
            int u = S.top();
            S.pop();
            V[u] = 2;
            aux = min(C[u], aux);
          }
          ans += aux;
          while (!S.empty()) {
            int u = S.top();
            S.pop();
            V[u] = 2;
          }
        } else if (V[v] == 2)
          while (!S.empty()) {
            int u = S.top();
            S.pop();
            V[u] = 2;
          }
      }
    }
  cout << ans << '\n';
  return 0;
}
