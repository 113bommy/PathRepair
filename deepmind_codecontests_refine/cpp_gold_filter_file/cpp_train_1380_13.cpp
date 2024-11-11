#include <bits/stdc++.h>
using namespace std;
long long query(vector<int> Q) {
  if (Q.empty()) return 0;
  cout << "? " << Q.size();
  for (auto x : Q) cout << ' ' << x;
  cout << endl;
  fflush(stdout);
  long long ret;
  cin >> ret;
  return ret;
}
int main() {
  ios::sync_with_stdio(false);
  cin.tie(0), cout.tie(0);
  vector<int> Q[13];
  array<int, 1001> num;
  int M = 13, cnt = 0, n;
  cin >> n;
  for (int i = 1; i < (1 << M); ++i)
    if (__builtin_popcount(i) == 6) {
      num[++cnt] = i;
      for (int j = 0; j < M; ++j)
        if (((i >> j) & 1) == 0) Q[j].push_back(cnt);
      if (cnt == n) break;
    }
  array<long long, 13> ORres{};
  for (int i = 0; i < M; ++i) ORres[i] = query(Q[i]);
  array<long long, 1001> ans{};
  for (int i = 1; i <= n; ++i)
    for (int j = 0; j < M; ++j)
      if ((num[i] >> j) & 1) ans[i] |= ORres[j];
  cout << "!";
  for (int i = 1; i <= n; ++i) cout << ' ' << ans[i];
  return 0;
}
