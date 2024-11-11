#include <bits/stdc++.h>
using namespace std;
const int N = 81;
int n, br_nula;
bool a[N];
int dp[N][N][N * N / 2];
vector<int> jed;
int func(int pos, int zad, int c) {
  if (c < 0) return -2 * 1e5;
  if (pos >= jed.size()) return 0;
  if (zad >= n - 1) return -2 * 1e5;
  if (dp[pos][zad][c] != -1) return dp[pos][zad][c];
  int ret = 0, x = jed[pos];
  for (int i = zad; i < n; i++) {
    int nule = br_nula - (i - pos);
    int dod = (i - zad) * nule;
    ret = max(ret, func(pos + 1, i + 1, c - abs(x - i)) + dod);
  }
  return dp[pos][zad][c] = ret;
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cin >> n;
  for (int i = 0; i < n; i++) {
    cin >> a[i];
    if (!a[i])
      br_nula++;
    else
      jed.push_back(i);
  }
  memset(dp, -1, sizeof dp);
  for (int i = 0; i <= n * (n - 1) / 2; i++) {
    cout << func(0, 0, i) << " ";
  }
  return 0;
}
