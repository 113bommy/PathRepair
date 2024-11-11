#include <bits/stdc++.h>
using namespace std;
int dy[] = {1, -1, 0, 0, -1, 1, 1, -1};
int dx[] = {0, 0, 1, -1, 1, -1, 1, -1};
void file() {}
void fast() {
  std::ios_base::sync_with_stdio(0);
  cin.tie(NULL);
}
void test_case() {
  int n;
  cin >> n;
  vector<vector<int> > adjL(n + 1);
  vector<pair<int, int> > v1(n);
  for (auto& it : v1) {
    cin >> it.first >> it.second;
    adjL[it.first].push_back(it.second);
  }
  long long ans = n * (n - 1) * (n - 2) / 6;
  vector<long long> fre(n + 1);
  for (int i = 1; i <= n; i++) {
    for (auto& it : adjL[i]) {
      ans -= fre[it];
    }
    for (auto& it : adjL[i]) fre[it] += (int)(adjL[i].size()) - 1;
  }
  fre = vector<long long>(n + 1);
  for (int i = n; i >= 1; i--) {
    for (auto& it : adjL[i]) ans -= fre[it];
    for (auto& it : adjL[i]) fre[it] += (int)(adjL[i].size()) - 1;
  }
  cout << ans << '\n';
}
int main() {
  file();
  fast();
  int t;
  cin >> t;
  while (t--) {
    test_case();
  }
  return 0;
}
