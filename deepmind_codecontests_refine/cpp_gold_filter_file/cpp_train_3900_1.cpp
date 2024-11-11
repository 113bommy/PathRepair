#include <bits/stdc++.h>
using namespace std;
int32_t main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);
  long long N;
  cin >> N;
  vector<vector<long long>> a(N + 1, vector<long long>(N + 1));
  vector<long long> d1(N << 1), d2(N << 1);
  for (long long i = 1; i <= N; ++i)
    for (long long j = 1; j <= N; ++j) {
      cin >> a[i][j];
      d1[i + j - 1] += a[i][j];
      d2[i - j + N] += a[i][j];
    }
  vector<long long> sol(2);
  vector<pair<long long, long long>> coords(2);
  for (long long i = 1; i <= N; ++i)
    for (long long j = 1; j <= N; ++j) {
      long long index = (i + j) & 1;
      long long cand = d1[i + j - 1] + d2[i - j + N] - a[i][j];
      if (cand >= sol[index]) {
        sol[index] = cand;
        coords[index] = make_pair(i, j);
      }
    }
  cout << sol[0] + sol[1] << '\n';
  for (const pair<long long, long long> &p : coords)
    cout << p.first << ' ' << p.second << ' ';
  cout << '\n';
}
