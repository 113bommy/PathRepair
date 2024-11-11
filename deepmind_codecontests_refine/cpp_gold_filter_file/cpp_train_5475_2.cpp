#include <bits/stdc++.h>
using namespace std;
const long long INF = 10000000000000000;
const int MOD = 1000000007;
const int MAXN = 5005;
int N, M;
int A[MAXN];
pair<int, int> B[MAXN];
long long D[2][MAXN], K[2][MAXN], sum[MAXN];
long long get_C(int t, int k, int m) {
  if (m - k + 1 > B[t].second) return INF;
  return sum[m] - sum[k - 1];
}
void dnc(int t, int l, int r, int s, int e) {
  if (l > r || s > e) return;
  int m = (l + r) / 2;
  K[t % 2][m] = max(s, m - B[t].second);
  for (int k = max(s, m - B[t].second); k <= e && k <= m; k++) {
    long long tmp = D[(t + 1) % 2][k] + get_C(t, k + 1, m);
    if (D[t % 2][m] > tmp) {
      D[t % 2][m] = tmp;
      K[t % 2][m] = k;
    }
  }
  dnc(t, l, m - 1, s, K[t % 2][m]);
  dnc(t, m + 1, r, K[t % 2][m], e);
}
void update_sum(int m) {
  sum[0] = 0;
  for (int i = 1; i <= N; i++) sum[i] = sum[i - 1] + abs(B[m].first - A[i]);
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cin >> N >> M;
  for (int i = 1; i <= N; i++) cin >> A[i];
  for (int i = 1; i <= M; i++) {
    int p, c;
    cin >> p >> c;
    B[i] = make_pair(p, c);
  }
  sort(A + 1, A + N + 1);
  sort(B + 1, B + M + 1);
  update_sum(1);
  for (int j = 1; j <= N; j++) D[1][j] = get_C(1, 1, j);
  long long ans = INF;
  for (int t = 2; t <= M; t++) {
    update_sum(t);
    for (int j = 1; j <= N; j++) {
      D[t % 2][j] = INF;
      K[t % 2][j] = 0;
    }
    dnc(t, 0, N, 0, N);
  }
  if (D[M % 2][N] == INF)
    cout << "-1\n";
  else
    cout << D[M % 2][N] << '\n';
}
