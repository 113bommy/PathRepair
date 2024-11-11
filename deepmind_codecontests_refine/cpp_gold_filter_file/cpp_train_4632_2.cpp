#include <bits/stdc++.h>
using namespace std;
int n, k, p, x, y, temp;
int i, total, cnt;
int main() {
  cin >> n >> k >> p >> x >> y;
  for (i = 0; i < k; i++) {
    cin >> temp;
    total += temp;
    if (temp < y) cnt++;
  }
  if (cnt > n / 2) {
    cout << "-1" << endl;
    return 0;
  }
  vector<int> res;
  int c;
  c = min(n - k, n / 2 - cnt);
  for (i = 0; i < c; i++) {
    res.push_back(1);
    total++;
  }
  for (i = 0; i < (n - k - c); i++) {
    res.push_back(y);
    total += y;
  }
  if (total > x) {
    cout << "-1" << endl;
    return 0;
  }
  for (i = 0; i < res.size(); i++) cout << res[i] << " ";
  cout << endl;
  return 0;
}
