#include <bits/stdc++.h>
using namespace std;
int main() {
  int n, a[2005], b[2005];
  long long int cnt = 0;
  map<pair<int, int>, int> m1;
  map<pair<int, int>, int>::iterator it;
  cin >> n;
  for (int i = 0; i < n; i++) {
    cin >> a[i] >> b[i];
  }
  for (int i = 0; i < n - 1; i++) {
    for (int j = i + 1; j < n; j++) {
      int x = a[j] - a[i];
      int y = b[j] - b[i];
      if (x < 0 && y < 0) {
        x = -x;
        y = -y;
      } else {
        if (x < 0 && y > 0) {
          x = -x;
          y = -y;
        }
      }
      m1[make_pair(x, y)]++;
    }
  }
  for (it = m1.begin(); it != m1.end(); it++) {
    int t = it->second;
    pair<int, int> tt = it->first;
    if (t > 1) cnt += t * (t - 1) / 2;
  }
  cout << cnt / 2 << endl;
}
