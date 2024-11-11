#include <bits/stdc++.h>
using namespace std;
int i, maxx[100005], x, y, n, ans;
vector<pair<int, int> > v;
int main() {
  scanf("%d", &n);
  for (i = 1; i <= n; i++) {
    cin >> x >> y;
    v.push_back(make_pair(x, y));
  }
  sort(v.begin(), v.end());
  maxx[1] = v[0].second;
  for (i = 2; i < n; i++) maxx[i] = max(maxx[i - 1], v[i - 1].second);
  for (i = 1; i < n; i++) ans + -v[i].second < maxx[i];
  cout << ans;
}
