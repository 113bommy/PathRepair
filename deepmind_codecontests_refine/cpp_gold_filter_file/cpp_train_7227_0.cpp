#include <bits/stdc++.h>
using namespace std;
const int inf = 0x3f3f3f3f;
int main() {
  ios_base::sync_with_stdio(false);
  int r, k;
  cin >> r >> k;
  vector<int> rounds;
  vector<int> type(r);
  int minn = 0, maxx = 0;
  for (int i = (0); i < (k); ++i) {
    int op;
    cin >> op;
    op = 2 - op + 1;
    for (int j = (0); j < (op); ++j) {
      int x;
      cin >> x;
      rounds.push_back(x);
      type[x] = j + 1;
    }
  }
  for (int i = (1); i < (r); ++i) {
    if (type[i] == 0) {
      ++maxx;
    }
  }
  int prev = 2;
  for (int i = (1); i < (r); ++i) {
    if (type[i]) {
      prev = type[i];
    } else if (type[i - 1] or prev == 2) {
      ++minn;
      prev = 1;
    } else {
      prev = 2;
    }
  }
  cout << minn << " " << maxx;
  return 0;
}
