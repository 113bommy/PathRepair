#include <bits/stdc++.h>
using namespace std;
int main() {
  cout.sync_with_stdio(false);
  cin.tie(nullptr);
  int n;
  cin >> n;
  vector<pair<int, int> > v;
  for (int i = 0; i < n; i++) {
    int x, w;
    cin >> x >> w;
    v.push_back(pair<int, int>(x + w, x - w));
  }
  sort(v.begin(), v.end());
  int res = 1, aux = v[0].second;
  for (int i = 1; i < n; i++)
    if (v[i].second > aux) {
      aux = v[i].first;
      res++;
    }
  cout << res << endl;
  return 0;
}
