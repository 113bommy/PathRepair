#include <bits/stdc++.h>
using namespace std;
int main() {
  int N, M;
  cin >> N >> M;
  vector<int> same[1000];
  vector<pair<int, int>> diff;
  for (int i = 0; i < M; i++) {
    int t, a, b;
    cin >> t >> a >> b;
    a--;
    b--;
    if (t) {
      same[a].push_back(b);
    } else {
      diff.push_back({a, b});
    }
  }
  int now = 2000, ans[1000];
  int r = 0;
  for (int i = 0; i < N; i++) {
    for (int a : same[i]) r = max(r, a);
    ans[i] = now;
    if (i >= r) now--;
  }
  for (auto& p : diff)
    if (ans[p.first] == ans[p.second]) {
      cout << "NO" << endl;
      return 0;
    }
  cout << "YES" << endl;
  for (int i = 0; i < N; i++) cout << ans[i] << " \n"[i == N - 1];
  return 0;
}
