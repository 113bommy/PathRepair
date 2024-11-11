#include <bits/stdc++.h>
using namespace std;
vector<int> dive[20005];
vector<int> ans[20005];
int main() {
  int t;
  cin >> t;
  while (t--) {
    int a, b, c, fs, sc, th, tot = 1e9;
    cin >> a >> b >> c;
    for (int i = 1; i <= 2e4; i++) {
      ans[i].clear();
      for (int j = 1; j * j <= i; j++) {
        if (i % j == 0) {
          ans[i].push_back(j);
          if (j * j != i) ans[i].push_back(i / j);
        }
      }
      sort(ans[i].begin(), ans[i].end());
    }
    for (int i = 1; i <= 2e4; i++) {
      dive[i].clear();
      for (int j = i; j <= 2e4; j += i) {
        dive[i].push_back(j);
      }
    }
    for (int i = 1; i <= 2e4; i++) sort(dive[i].begin(), dive[i].end());
    for (int i = 1; i <= 2e4; i++) {
      int res = abs(i - b);
      int x = -1;
      if (ans[i].size())
        x = lower_bound(ans[i].begin(), ans[i].end(), a) - ans[i].begin();
      if (x == -1) continue;
      if (x >= ans[i].size()) x--;
      int number1 = ans[i][x];
      int first = abs(ans[i][x] - a);
      int second = 1e9;
      if (x > 0) x--;
      x = max(x, 0);
      int number2 = ans[i][x];
      second = abs(ans[i][x] - a);
      res += min(first, second);
      x = -1;
      if (dive[i].size())
        x = lower_bound(dive[i].begin(), dive[i].end(), c) - dive[i].begin();
      if (x == -1) continue;
      if (x >= dive[i].size()) x--;
      x = max(x, 0);
      int third = abs(dive[i][x] - c);
      int number3 = dive[i][x];
      if (x > 0) x--;
      int fourth = abs(dive[i][x] - c);
      int number4 = dive[i][x];
      res += min(third, fourth);
      if (res < tot) {
        tot = res;
        if (first < second)
          fs = number1;
        else
          fs = number2;
        if (third < fourth)
          th = number3;
        else
          th = number4;
        sc = i;
      }
    }
    cout << tot << endl;
    cout << fs << " " << sc << " " << th << endl;
  }
  return 0;
}
