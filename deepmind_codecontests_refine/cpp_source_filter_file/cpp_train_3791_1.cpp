#include <bits/stdc++.h>
using namespace std;
const int inft = 1000000009;
const int MAXN = 1000006;
int maxi[MAXN], sum[MAXN], C[MAXN], V[MAXN];
pair<int, int> P[MAXN];
void solve() {
  int n, m;
  scanf("%d%d", &n, &m);
  for (int i = 0; i < (n); ++i) maxi[i] = inft;
  for (int _ = 0; _ < (m); ++_) {
    scanf("%d%d%d%d", &C[_], &P[_].first, &P[_].second, &V[_]);
    P[_].first--;
    P[_].second--;
    if (C[_] == 1) {
      for (int i = P[_].first; i <= P[_].second; i++) sum[i] += V[_];
    } else {
      for (int i = P[_].first; i <= P[_].second; i++)
        maxi[i] = min(maxi[i], -sum[i] + V[_]);
    }
  }
  for (int i = 0; i < (n); ++i) sum[i] = maxi[i];
  bool ok = 1;
  for (int _ = 0; _ < (m); ++_) {
    if (C[_] == 1) {
      for (int i = P[_].first; i <= P[_].second; i++) maxi[i] += V[_];
    } else {
      bool oki = 0;
      for (int i = P[_].first; i <= P[_].second; i++)
        if (maxi[i] == V[_]) oki = 1;
      if (!oki) ok = 0;
    }
  }
  puts(ok ? "YES" : "NO");
  if (ok)
    for (int i = 0; i < (n); ++i) printf("%d ", sum[i]);
  puts("");
}
int main() {
  int t = 1;
  for (int i = 0; i < (t); ++i) solve();
  return 0;
}
