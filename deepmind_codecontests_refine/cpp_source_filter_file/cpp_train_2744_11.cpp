#include <bits/stdc++.h>
using namespace std;
int main() {
  ios_base::sync_with_stdio(0);
  int n, diff;
  cin >> n;
  int h, m, cashes = 1, min_cashes = 1;
  vector<int> time;
  while (n--) {
    cin >> h >> m;
    time.push_back(h * 60 + m);
  }
  for (int i = 0; i < time.size(); ++i) {
    if (time[i] == time[i + 1]) {
      ++cashes;
      if (min_cashes < cashes) {
        min_cashes = cashes;
      }
    } else {
      cashes = 1;
    }
  }
  cout << min_cashes << endl;
  return 0;
}
