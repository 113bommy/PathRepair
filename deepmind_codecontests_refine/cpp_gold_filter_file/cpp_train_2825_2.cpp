#include <bits/stdc++.h>
using namespace std;
int main() {
  int n = ({
    int t;
    scanf("%d", &t);
    t;
  });
  vector<pair<int, int> > v;
  if (n == 4) {
    cout << 4;
    return 0;
  }
  for (int i = 0; i < n; i++) {
    if (n - 4 * i < 0) break;
    int k = n - 4 * i;
    if (k % 7 == 0) v.push_back(make_pair(i, k / 7));
  }
  if (v.size() == 0) {
    cout << -1;
    return 0;
  }
  int res = 1 << 30, res7 = 1 << 30;
  for (int i = 0; i < v.size(); i++) res = min(res, v[i].first + v[i].second);
  for (int i = 0; i < v.size(); i++)
    if (res == v[i].first + v[i].second) res7 = min(res7, v[i].second);
  int res4 = (n - res7 * 7) / 4;
  for (int i = 0; i < res4; i++) cout << 4;
  for (int i = 0; i < res7; i++) cout << 7;
  return 0;
}
