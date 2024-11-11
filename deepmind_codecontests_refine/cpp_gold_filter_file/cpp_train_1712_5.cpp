#include <bits/stdc++.h>
using namespace std;
const int N = 1e5 + 100;
vector<int> b[N];
int a[N];
int main() {
  int n, m;
  cin >> n >> m;
  for (int i = 1; i <= m; i++) cin >> a[i];
  for (int i = 1; i <= m; i++) {
    if (i > 1 && a[i - 1] != a[i]) b[a[i - 1]].push_back(a[i]);
    if (i < m && a[i + 1] != a[i]) b[a[i + 1]].push_back(a[i]);
  }
  long long sum = 0;
  long long ans = 0;
  for (int i = 1; i <= n; i++) {
    if (b[i].empty()) continue;
    sort(b[i].begin(), b[i].end());
    long long s = b[i][b[i].size() / 2];
    long long af = 0, bef = 0;
    for (int j = 0; j < b[i].size(); j++) {
      bef += abs(i - b[i][j]);
      af += abs(s - b[i][j]);
    }
    ans = max(ans, bef - af);
    sum += bef;
  }
  sum = (sum / 2) - ans;
  cout << sum << endl;
  return 0;
}
