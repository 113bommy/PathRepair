#include <bits/stdc++.h>
#pragma GCC optimize("O2")
using namespace std;
const long long MAX = 1e3 + 5;
const long long MAX2 = 11;
const int MOD = 1000000000 + 7;
const long long INF = 20000;
const int nr[] = {1, 0, -1, 0, 1, 1, -1, -1};
const int nc[] = {0, 1, 0, -1, 1, -1, 1, -1};
int a, b, cek;
vector<pair<int, int> > v[1005];
int main() {
  cout << fixed << setprecision(6);
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  for (long long i = 1; i <= 1000; ++i)
    for (long long j = i + 1; j <= 1000; ++j) {
      cek = sqrt(i * i + j * j);
      if (cek * cek == i * i + j * j && cek < 1001) v[cek].push_back({i, j});
    }
  cin >> a >> b;
  if (v[a].empty() || v[b].empty()) return cout << "NO", 0;
  for (auto i : v[a]) {
    for (auto j : v[b]) {
      cek = (i.first + j.second) * (i.first + j.second) +
            (i.second - j.first) * (i.second - j.first);
      if (cek == a * a + b * b && i.second != j.first)
        return cout << "YES\n0 0\n"
                    << i.first << " " << i.second << "\n"
                    << -j.second << " " << j.first,
               0;
    }
  }
  cout << "NO";
  return 0;
}
