#include <bits/stdc++.h>
using namespace std;
int main() {
  int n, m;
  cin >> n >> m;
  int k[101] = {0};
  for (int i = 0; i < n; i++) {
    int c;
    cin >> c;
    c--;
    k[c]++;
  }
  vector<pair<int, int> > v;
  for (int i = 0; i < m; i++)
    if (k[i] > 0) v.push_back(make_pair(k[i] * 2, i));
  sort(v.begin(), v.end());
  reverse(v.begin(), v.end());
  int ans[5001][2];
  int kol = 0;
  int j = 0;
  for (int i = 0; i < n; i++) {
    ans[i][i % 2] = v[j].second + 1;
    v[j].first--;
    if (v[j].first == 0) j++;
  }
  for (int i = 0; i < n; i++) {
    ans[i][(i + 1) % 2] = v[j].second + 1;
    v[j].first--;
    if (v[j].first == 0) j++;
    if (ans[i][0] == ans[i][1]) kol++;
  }
  cout << kol << endl;
  for (int i = 0; i < n; i++) cout << ans[i][0] << " " << ans[i][1] << endl;
  return 0;
}
