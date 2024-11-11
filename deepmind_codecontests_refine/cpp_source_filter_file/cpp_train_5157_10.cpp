#include <bits/stdc++.h>
using namespace std;
pair<int, int> p[1010];
int dir[1010];
int turn[1010];
int main() {
  int n;
  while (cin >> n) {
    for (int i = 0; i <= n; i++) cin >> p[i].first >> p[i].second;
    for (int i = 0; i < n; i++) {
      int j = (i + 1) % n;
      if (p[i].first == p[j].first) {
        if (p[i].second < p[j].second)
          dir[i] = 0;
        else
          dir[i] = 2;
      } else if (p[i].first < p[i].second)
        dir[i] = 1;
      else
        dir[i] = 3;
    }
    int l = 0;
    int r = 0;
    for (int i = 1; i < n; i++) {
      turn[i] = dir[i] - dir[i - 1];
      if (turn[i] < 0)
        l++;
      else
        r++;
    }
    if (dir[0] == 0)
      cout << l << endl;
    else
      cout << r << endl;
  }
  return 0;
}
