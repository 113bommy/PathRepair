#include <bits/stdc++.h>
using namespace std;
const int maxn = 100 + 10;
vector<int> v[maxn];
set<int> s;
int num[maxn];
bool cmp(int x, int y) { return num[x] > num[y]; }
int main() {
  int n, m, k;
  cin >> n >> m >> k;
  for (int i = 1; i <= n; i++) cin >> num[i];
  for (int i = 1; i <= n; i++) {
    int tmp;
    cin >> tmp;
    v[tmp].push_back(i);
  }
  for (int i = 0; i < k; i++) {
    int tmp;
    cin >> tmp;
    s.insert(tmp);
  }
  for (int i = 1; i <= n; i++) sort(v[i].begin(), v[i].end(), cmp);
  int ans = 0;
  for (int i = 1; i <= n; i++) {
    for (int j = 1; j < int(v[i].size()); j++) {
      if (s.count(v[i][j])) {
        ans++;
        s.erase(v[i][j]);
      }
    }
  }
  cout << ans << "\n";
  return 0;
}
