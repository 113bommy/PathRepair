#include <bits/stdc++.h>
using namespace std;
int main() {
  ios_base::sync_with_stdio(false);
  int n, k;
  cin >> n >> k;
  vector<pair<int, int>> x(n), y(n);
  for (int i = 0; i < n; ++i) {
    int x1, y1, x2, y2;
    cin >> x1 >> y1 >> x2 >> y2;
    x[i] = make_pair(x1 + x2, i);
    y[i] = make_pair(y1 + y2, i);
  }
  sort(x.begin(), x.end());
  sort(y.begin(), y.end());
  vector<int> del;
  long long int answ = 1e18;
  for (int i = 0; i <= k; ++i) {
    for (int j = 0; j <= k - i; ++j) {
      del.clear();
      for (int l = 0; l < i; ++l) {
        del.push_back(x[l].second);
      }
      for (int l = 0; l < j; ++l) {
        del.push_back(x[n - l - 1].second);
      }
      size_t del_size = del.size();
      for (int l = 0; l <= k - i - j; ++l) {
        del.resize(del_size);
        int a = 0;
        for (int cnt = 0; cnt < l; ++cnt) {
          while (find(del.begin(), del.end(), y[a].second) != del.end()) {
            ++a;
          }
          del.push_back(y[a++].second);
        }
        int b = n - 1;
        for (int cnt = 0; cnt < k - i - j - l; ++cnt) {
          while (find(del.begin(), del.end(), y[b].second) != del.end()) {
            --b;
          }
          del.push_back(y[b--].second);
        }
        int c = i;
        while (find(del.begin(), del.end(), x[c].second) != del.end()) {
          ++c;
        }
        int d = n - 1 - j;
        while (find(del.begin(), del.end(), x[d].second) != del.end()) {
          --d;
        }
        answ = min(
            answ,
            static_cast<long long int>(max(2, x[d].first - x[c].first)) *
                static_cast<long long int>(max(2, y[b].first - y[a].first)));
      }
    }
  }
  cout << answ / 4;
  return 0;
}
