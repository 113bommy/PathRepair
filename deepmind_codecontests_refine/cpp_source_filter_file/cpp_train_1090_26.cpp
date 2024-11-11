#include <bits/stdc++.h>
using namespace std;
int const H = 55;
int h;
long long n;
long long pot(int exp) {
  long long ret = 1;
  for (int i = 1; i <= (int)exp; i++) ret *= 2;
  return ret;
}
long long solve(long long i, long long j, int height, int last) {
  if (i == j) return 0;
  long long mid = (i + j) / 2;
  if (last == -1) {
    if (i <= n && n <= mid) return solve(i, mid, height - 1, 0);
    return solve(mid + 1, j, height - 1, 1) + pot(height);
  }
  if (i <= n && n <= mid) {
    if (!last) return solve(i, mid, height - 1, last) + pot(height);
    return solve(i, mid, height - 1, last ^ 1) + 1;
  }
  if (last) return solve(mid + 1, j, height - 1, last) + pot(height);
  return solve(mid + 1, j, height - 1, last ^ 1) + 1;
}
int main() {
  cin.sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  cin >> h >> n;
  long long fim = pot(h);
  long long ans = solve(1, fim, h, -1);
  cout << ans;
}
