#include <bits/stdc++.h>
using namespace std;
int n, ar[300001][2] = {}, ans[300001] = {};
deque<pair<int, int> > mx[2] = {};
int main() {
  cin >> n;
  for (int i = 0; i < n; i++) {
    cin >> ar[i][0];
    ar[i][1] = ar[i][0];
    ans[n - 1] = max(ans[n - 1], ar[i][0]);
  }
  for (int i = 0; i < n - 1; i++) {
    ar[i][0] = max(ar[i][0], ar[i + 1][0]);
    ar[i][1] = min(ar[i][1], ar[i + 1][1]);
  }
  for (int i = 0; i < n - 2; i++) {
    ar[i][1] = max(ar[i][1], ar[i + 1][1]);
  }
  for (int i = 0; i <= n - 2 - i; i++) {
    int m = max(ar[i][0], ar[n - 2 - i][0]);
    while (mx[0].size() && mx[0].back().first <= m) {
      mx[0].pop_back();
    }
    mx[0].push_back({m, i});
  }
  for (int i = 0; i <= n - 3 - i; i++) {
    int m = max(ar[i][1], ar[n - 3 - i][1]);
    while (mx[1].size() && mx[1].back().first <= m) {
      mx[1].pop_back();
    }
    mx[1].push_back({m, i});
  }
  for (int i = 0; i < n - 1; i++) {
    ans[n - 2 - i] = mx[i % 2].front().first;
    if (mx[i % 2].front().second == i / 2) {
      mx[i % 2].pop_front();
    }
  }
  for (int i = 0; i < n; i++) {
    cout << ans[i];
    if (i < n - 1) {
      cout << " ";
    }
  }
  cout << "\n";
  return 0;
}
