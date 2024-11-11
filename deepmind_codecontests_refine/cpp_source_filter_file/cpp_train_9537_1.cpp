#include <bits/stdc++.h>
using namespace std;
struct query {
  int le, ri, k;
  int pos;
};
query q[300005];
int bucketSize;
int N, Q;
int A[300005];
int Freq[300005];
int ans[300005];
int getRandIndex(int le, int ri) {
  return le + 1ll * rand() * rand() % (ri - le + 1);
}
bool qx(query a, query b) {
  if (a.le / bucketSize != b.le / bucketSize)
    return a.le / bucketSize < b.le / bucketSize;
  if (a.le / bucketSize & 1) return a.ri < b.ri;
  return a.ri > b.ri;
}
int main() {
  srand(time(NULL));
  ios::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  cin >> N >> Q;
  bucketSize = sqrt(N);
  for (int i = 1; i <= N; i++) cin >> A[i];
  for (int i = 1; i <= Q; i++)
    cin >> q[i].le >> q[i].ri >> q[i].k, q[i].pos = i;
  sort(q + 1, q + Q + 1, qx);
  int L = 1;
  int R = N;
  for (int i = 1; i <= N; i++) Freq[A[i]]++;
  for (int i = 1; i <= Q; i++) {
    while (L < q[i].le) Freq[A[L++]]--;
    while (L > q[i].le) Freq[A[--L]]++;
    while (R < q[i].ri) Freq[A[++R]]++;
    while (R > q[i].ri) Freq[A[R--]]--;
    int mi = INT_MAX;
    for (int zz = 25; zz; zz--) {
      int pos = getRandIndex(L, R);
      if (Freq[A[pos]] > (R - L + 1) / q[i].k) mi = min(mi, A[pos]);
    }
    ans[q[i].pos] = (mi == INT_MAX ? -1 : mi);
  }
  for (int i = 1; i <= Q; i++) cout << ans[i] << "\n";
  return 0;
}
