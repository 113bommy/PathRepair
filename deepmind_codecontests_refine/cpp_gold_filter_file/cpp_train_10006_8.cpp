#include <bits/stdc++.h>
using namespace std;
const int N = 1e3 + 10, D = 4;
int dx[D] = {0, -1, 0, 1};
int dy[D] = {-1, 0, 1, 0};
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  int n;
  cin >> n;
  vector<pair<int, int> > ans = {{0, 0}};
  --n;
  for (int i = 1; i < N and n; ++i) {
    for (int d = 0; d < 4 and n; ++d) {
      ans.push_back({i * dx[d], i * dy[d]});
      --n;
    }
  }
  for (auto &p : ans) {
    cout << p.first << ' ' << p.second << '\n';
  }
}
