#include <bits/stdc++.h>
using namespace std;
int dx[] = {0, 0, 1, -1};
int dy[] = {1, -1, 0, 0};
int dx8[] = {0, 0, 1, 1, 1, -1, -1, -1};
int dy8[] = {1, -1, -1, 0, 1, -1, 0, 1};
int kx8[] = {1, 1, 2, 2, -1, -1, -2, -2};
int ky8[] = {2, -2, 1, -1, 2, -2, 1, -1};
const int M = 100005;
long long a[M], b[M], dp[M];
long long Slope[M], C[M], hsz;
long long get(long long id, long long x) { return (Slope[id] * x + C[id]); }
double cross(int x, int y) {
  return (double)(C[x] - C[y]) / (Slope[y] - Slope[x]);
}
void AddLine(long long p, long long q) {
  if (hsz > 0 && Slope[hsz] == p) {
    if (C[hsz] < q)
      hsz--;
    else
      return;
  }
  Slope[++hsz] = p;
  C[hsz] = q;
  while (hsz >= 3 && cross(hsz - 2, hsz - 1) > cross(hsz - 2, hsz)) {
    --hsz;
    Slope[hsz] = Slope[hsz + 1];
    C[hsz] = C[hsz + 1];
  }
}
long long query(long long x) {
  long long lw = 1, hi = hsz, mid, midd, ans = 1e18;
  while (hi - lw > 10) {
    mid = (lw + hi) / 2;
    midd = min(hsz, mid + 1);
    if (get(mid, x) < get(midd, x)) {
      hi = mid - 1;
      ans = get(mid, x);
    } else {
      lw = midd + 1;
      ans = get(midd, x);
    }
  }
  for (long long i = lw; i <= hi; i++) {
    ans = min(ans, get(i, x));
  }
  return ans;
}
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  int n;
  cin >> n;
  for (int i = 1; i <= n; i++) cin >> a[i];
  for (int i = 1; i <= n; i++) cin >> b[i];
  dp[1] = 0;
  AddLine(b[1], 0);
  for (int i = 2; i <= n; i++) {
    dp[i] = query(a[i]);
    AddLine(b[i], dp[i]);
  }
  cout << dp[n] << endl;
  return 0;
}
