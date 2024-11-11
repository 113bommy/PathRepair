#include <bits/stdc++.h>
using namespace std;
int main() {
  int n;
  double b;
  cin >> n >> b;
  vector<int> array(n);
  vector<double> ans(n);
  for (int i = 0; i < n; ++i) {
    cin >> array[i];
  }
  int _max = *max_element(array.begin(), array.end());
  int _min = 0;
  for (int i = 0; i < n; ++i) {
    if (array[i] != _max) {
      _min += _max - array[i];
    }
  }
  if (_min > b) {
    cout << -1;
    return 0;
  } else {
    for (int i = 0; i < n; ++i) {
      ans[i] = _max - array[i];
      b -= (_max - array[i]);
    }
    if (b > 0) {
      double _else = b / n;
      for (int i = 0; i < n; ++i) {
        ans[i] += _else;
      }
    }
    cout.precision(6);
    for (int i = 0; i < n; ++i) {
      cout << fixed << ans[i] << endl;
    }
  }
  return 0;
}
