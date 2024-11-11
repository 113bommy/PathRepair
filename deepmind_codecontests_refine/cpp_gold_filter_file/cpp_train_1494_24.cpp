#include <bits/stdc++.h>
using namespace std;
const int inf = (int)1e9;
const double EPS = 1e-9, INF = 1e12;
int n, m, k, a[200000], ans;
vector<int> v[100010];
int main() {
  cin >> n >> m >> k;
  for (int i = 0; i < (int)n; i++) {
    cin >> a[i];
    v[a[i]].push_back(i);
  }
  for (int it = 0; it < (int)100010; it++) {
    vector<int> &b = v[it];
    int i = 0, j = 0, skip = 0;
    for (; i < b.size(); i++) {
      while (j < b.size()) {
        if (i != j && skip + b[j] - b[j - 1] - 1 > k) break;
        if (i < j) skip += b[j] - b[j - 1] - 1;
        j++;
      }
      ans = max(ans, j - i);
      if (i + 1 < j) skip -= b[i + 1] - b[i] - 1;
    }
  }
  cout << ans << endl;
  return 0;
}
