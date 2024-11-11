#include <bits/stdc++.h>
using namespace std;
const int N = 1e5 + 10;
int n, m;
vector<pair<int, int> > a;
int main() {
  ios_base::sync_with_stdio(false);
  cin >> n;
  for (int i = 1; i <= n; i++) {
    int x, y;
    cin >> x >> y;
    a.push_back(pair<int, int>(x, y));
  }
  cin >> m;
  for (int i = 1; i <= m; i++) {
    int x, y;
    cin >> x >> y;
    a.push_back(pair<int, int>(x, y));
  }
  sort(a.begin(), a.end());
  long long res = 0;
  int i = 0;
  while (i < int(a.size())) {
    if (i < int(a.size()) - 1 && a[i].first == a[i + 1].first &&
        a[i].second <= a[i + 1].second) {
      res += a[i + 1].second;
      i += 2;
    } else {
      res += a[i].second;
      i++;
    }
  }
  cout << res;
}
