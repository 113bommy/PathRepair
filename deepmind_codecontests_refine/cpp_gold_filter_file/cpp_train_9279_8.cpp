#include <bits/stdc++.h>
using namespace std;
long long n, x, y;
int main() {
  cin >> n >> x >> y;
  long long s = 0;
  vector<long long> res;
  if (n > y) {
    cout << -1 << endl;
    return 0;
  }
  for (int i = 0; i < n - 1; i++) {
    res.push_back(1LL);
  }
  res.push_back(y - n + 1LL);
  for (int i = 0; i < n; i++) {
    s += res[i] * res[i];
  }
  if (s < x) {
    cout << -1 << endl;
  } else {
    for (int i = 0; i < n; i++) {
      cout << res[i] << endl;
    }
  }
}
