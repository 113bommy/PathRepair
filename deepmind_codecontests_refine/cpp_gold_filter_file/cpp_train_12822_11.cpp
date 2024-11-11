#include <bits/stdc++.h>
using namespace std;
long long n, m, k, p[100001];
int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  cin >> n >> m >> k;
  for (long long i = (1); i < (m + 1); ++i) cin >> p[i];
  p[0] = 0;
  long long &ans = p[0];
  int idx = 1, h = 0;
  while (idx <= m) {
    long long lim = (p[idx] - h - 1) / k * k + k;
    ans++;
    while (idx <= m && p[idx] - h <= lim) idx++;
    h = idx - 1;
  }
  cout << ans << endl;
  return 0;
}
