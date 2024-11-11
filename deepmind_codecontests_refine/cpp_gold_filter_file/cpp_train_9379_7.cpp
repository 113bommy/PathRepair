#include <bits/stdc++.h>
using namespace std;
int x11[200010], x2[200010], y11[200010], y2[200010];
int n;
bool verif(int x, int y) {
  int count = n;
  for (int i = 1; i <= n; i++) {
    if (x11[i] > x || x2[i] < x || y11[i] > y || y2[i] < y) count--;
  }
  return count >= n - 1;
}
int main() {
  vector<int> open, close;
  cin >> n;
  for (int i = 1; i <= n; i++) {
    cin >> x11[i] >> y11[i] >> x2[i] >> y2[i];
    open.push_back(x11[i]);
    close.push_back(x2[i]);
  }
  vector<int> posibilx, posibily;
  sort(open.begin(), open.end());
  sort(close.begin(), close.end());
  int cnt = 0;
  for (int i = 0, j = 0; i < n; i++) {
    while (j < close.size() && close[j] < open[i]) cnt--, j++;
    cnt++;
    if (cnt >= n - 1) posibilx.push_back(open[i]);
  }
  open.clear();
  close.clear();
  for (int i = 1; i <= n; i++) {
    open.push_back(y11[i]);
    close.push_back(y2[i]);
  }
  sort(open.begin(), open.end());
  sort(close.begin(), close.end());
  cnt = 0;
  for (int i = 0, j = 0; i < n; i++) {
    while (j < close.size() && close[j] < open[i]) cnt--, j++;
    cnt++;
    if (cnt >= n - 1) posibily.push_back(open[i]);
  }
  for (auto i : posibilx) {
    for (auto j : posibily) {
      if (verif(i, j)) {
        cout << i << ' ' << j << '\n';
        return 0;
      }
    }
  }
  return 0;
}
