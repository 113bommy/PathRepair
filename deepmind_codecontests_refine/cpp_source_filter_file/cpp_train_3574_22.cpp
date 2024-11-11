#include <bits/stdc++.h>
using namespace std;
vector<int> v;
int main() {
  int T, x, a, up, low, mid;
  cin >> T >> x;
  for (int i = 0; i < T; i++) {
    cin >> a;
    v.push_back(a);
  }
  sort(v.begin(), v.end());
  mid = (T + 1) / 2;
  if (v[mid - 1] == x) {
    cout << "0" << endl;
    return 0;
  }
  up = upper_bound(v.begin(), v.end(), x) - v.begin();
  low = lower_bound(v.begin(), v.end(), x) - v.begin();
  if (up <= mid) {
    cout << T - 2 * up << endl;
  } else {
    cout << low * 2 + 1 - T << endl;
  }
  return 0;
}
