#include <bits/stdc++.h>
using namespace std;
const int MAXN = 2e5 + 5;
int N, X, Y;
long long A[5][MAXN];
vector<int> V[MAXN];
void dfs(int par, int now) {
  A[1][now] = 1;
  A[4][now] = MAXN;
  for (int next : V[now]) {
    if (next == par) {
      continue;
    }
    dfs(now, next);
    A[0][now] += A[2][next];
    A[1][now] += min(A[0][next], min(A[1][next], A[2][next]));
    A[2][now] += min(A[1][next], A[2][next]);
    A[3][now] += A[1][next] - 1;
    A[4][now] = min(A[4][now], A[1][next] - min(A[1][next], A[2][next]));
  }
  A[2][now] += A[4][now];
  return;
}
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  cin >> N;
  for (int i = 1; i < N; i++) {
    cin >> X >> Y;
    V[X].push_back(Y);
    V[Y].push_back(X);
  }
  dfs(0, 1);
  cout << A[3][1] << '\n';
  return 0;
}
