#include <bits/stdc++.h>
using namespace std;
int main() {
  int n;
  cin >> n;
  vector<int> vec;
  for (int i = 0; i < n; i++) {
    int k;
    cin >> k;
    vec.push_back(k);
  }
  int ans = -99;
  int _counter = 0;
  for (int i = 0; i < (2 * n); i++) {
    if (vec[i % n] == 1) {
      _counter++;
      ans = max(ans, _counter);
    } else
      _counter = 0;
  }
  cout << ans << endl;
  return 0;
}
