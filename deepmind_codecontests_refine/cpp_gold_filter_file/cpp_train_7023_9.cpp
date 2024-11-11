#include <bits/stdc++.h>
using namespace std;
const int INF = 0x3f3f3f3f;
const double EPS = 0.000000001;
const double PI = 3.141592653589793;
const long long LLINF = 99999999999999999LL;
const int MAX_N = 1005;
const int MOD = 1000000007;
int N, M;
char A[MAX_N][MAX_N];
bool out[MAX_N];
int cmp(int x, int y) {
  for (int j = 1; j <= M; ++j)
    if (out[j] == 0 && A[x][j] > A[y][j])
      return j;
    else if (out[j] == 0 && A[x][j] < A[y][j])
      return 0;
  return 0;
}
int main() {
  cin >> N >> M;
  for (int i = 1; i <= N; ++i) cin >> (A[i] + 1);
  int ans = 0, ok = 1;
  while (ok) {
    ok = 0;
    for (int i = 1; i < N; ++i) {
      int p = cmp(i, i + 1);
      if (!p) continue;
      out[p] = 1;
      ok = 1;
    }
  }
  for (int i = 1; i <= M; ++i)
    if (out[i]) ++ans;
  cout << ans;
  return 0;
}
