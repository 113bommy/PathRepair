#include <bits/stdc++.h>
using namespace std;
int N, M;
pair<int, int> A[100005];
long long X[100005];
long long Arb[100005], Arb2[400005], DP[100005], DP2[100005];
void Read() {
  scanf("%d%d", &N, &M);
  for (long long i = 1; i <= N; i++) scanf("%d%d", &A[i].first, &A[i].second);
}
void Upd(long long pos, long long val) {
  while (pos <= M) {
    Arb[pos] += val;
    pos += (pos & (-pos));
  }
}
long long Sum(long long pos) {
  long long ans = 0;
  while (pos >= 1) {
    ans += Arb[pos];
    pos -= (pos & (-pos));
  }
  return ans;
}
void precalcX() {
  for (long long i = 1; i <= N; i++) {
    Upd(A[i].first, 1);
    Upd(A[i].second + 1, -1);
  }
  for (long long i = 1; i <= M; i++) X[i] = Sum(i);
}
void Update(long long K, long long L, long long R, long long pos,
            long long val) {
  if (L > R) return;
  if (L == R) {
    Arb2[K] = val;
    return;
  }
  if (pos > (L + R) / 2)
    Update(K * 2 + 1, (L + R) / 2 + 1, R, pos, val);
  else
    Update(K * 2, L, (L + R) / 2, pos, val);
  Arb2[K] = max(Arb2[K * 2 + 1], Arb2[K * 2]);
}
long long Query(long long K, long long L, long long R, long long x,
                long long y) {
  if (L > R || L > y || R < x) return 0;
  if (L >= x && R <= y) return Arb2[K];
  long long a = Query(K * 2, L, (L + R) / 2, x, y);
  long long b = Query(K * 2 + 1, (L + R) / 2 + 1, R, x, y);
  return max(a, b);
}
void precalcDPLeft() {
  for (long long i = 1; i <= M; i++) {
    long long nb = Query(1, 1, N, 1, X[i]);
    DP[i] = nb + 1;
    Update(1, 1, N, X[i], nb + 1);
  }
  for (long long i = 1; i <= N * 4; i++) Arb2[i] = 0;
}
void precalcDPRight() {
  for (long long i = M; i >= 1; i--) {
    long long nb = Query(1, 1, N, 1, X[i]);
    DP2[i] = nb + 1;
    Update(1, 1, N, X[i], nb + 1);
  }
}
void Solve() {
  long long ans = 0;
  for (long long i = 1; i <= M; i++) ans = max(ans, DP2[i] + DP[i]);
  cout << ans - 1 << "\n";
}
int main() {
  Read();
  precalcX();
  precalcDPLeft();
  precalcDPRight();
  Solve();
  return 0;
}
