#include <bits/stdc++.h>
using namespace std;
const int N = 3e5 + 111;
const int K = 18;
int n, a;
int d[N], c[N];
int lo[N];
long long ans = 0;
long long pref[N];
long long maxi[N][K + 1];
long long mini[N][K + 1];
long long Min(int l, int r) {
  int j = lo[r - l + 1];
  return min(mini[l][j], mini[r - (1 << j) + 1][j]);
}
long long Max(int l, int r) {
  int j = lo[r - l + 1];
  return max(maxi[l][j], maxi[r - (1 << j) + 1][j]);
}
int L[N], R[N];
int main() {
  for (int i = 2; i <= N - 1; ++i) lo[i] = lo[i / 2] + 1;
  scanf("%d%d", &n, &a);
  for (int i = 1; i <= n; ++i) {
    scanf("%d%d", d + i, c + i);
    ans = max(ans, (long long)a - c[i]);
    pref[i] = pref[i - 1] + a - c[i];
    maxi[i][0] = pref[i];
    mini[i][0] = pref[i];
  }
  for (int j = 1; j <= K; ++j)
    for (int i = 1; i <= n - (1 << j) + 1; ++i) {
      maxi[i][j] = max(maxi[i][j - 1], maxi[i + (1 << (j - 1))][j - 1]);
      mini[i][j] = min(mini[i][j - 1], mini[i + (1 << (j - 1))][j - 1]);
    }
  vector<pair<long long, int>> val;
  for (int i = 1; i <= n - 1; ++i) {
    long long x = (long long)(d[i + 1] - d[i]) * (d[i + 1] - d[i]);
    while ((int)val.size() && val.back().first < x) {
      R[val.back().second] = i;
      val.pop_back();
    }
    val.push_back({x, i});
  }
  while ((int)val.size()) {
    R[val.back().second] = n;
    val.pop_back();
  }
  for (int i = n - 1; 1 <= i; --i) {
    long long x = (long long)(d[i + 1] - d[i]) * (d[i + 1] - d[i]);
    while ((int)val.size() && val.back().first <= x) {
      L[val.back().second] = i + 1;
      val.pop_back();
    }
    val.push_back({x, i});
  }
  while ((int)val.size()) {
    L[val.back().second] = 1;
    val.pop_back();
  }
  for (int i = 1; i <= n - 1; ++i) {
    ans = max(ans, Max(i + 1, R[i]) - Min(L[i] - 1, i - 1) -
                       (long long)(d[i + 1] - d[i]) * (d[i + 1] - d[i]));
  }
  printf("%lld", ans);
  return 0;
}
