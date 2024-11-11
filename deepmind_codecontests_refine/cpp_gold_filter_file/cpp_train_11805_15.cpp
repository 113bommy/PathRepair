#include <bits/stdc++.h>
using namespace std;
pair<int, int> directions[4] = {pair<int, int>(1, 0), pair<int, int>(-1, 0),
                                pair<int, int>(0, 1), pair<int, int>(0, -1)};
int main() {
  int n, m, k;
  cin >> n >> m >> k;
  map<int, int> cnt;
  int biggest = -1;
  for (int i = 0; i < n; i++) {
    int x;
    scanf("%d", &x);
    if (cnt.find(x) != cnt.end())
      cnt[x]++;
    else
      cnt[x] = 1;
  }
  for (int i = 0; i < m; i++) {
    int x;
    scanf("%d", &x);
    if (cnt.find(x) != cnt.end()) {
      cnt[x]--;
    } else {
      cnt[x] = -1;
    }
  }
  int bad = 0;
  int good = 0;
  for (auto y = cnt.rbegin(); y != cnt.rend(); ++y) {
    int x = y->second;
    if (x < 0) bad -= x;
    if (x > 0) {
      good += x;
      if (good > bad) {
        cout << "YES" << endl;
        return 0;
      }
    }
  }
  cout << "NO" << endl;
}
