#include <bits/stdc++.h>
using namespace std;
int main() {
  int n, k, x, cnt = 0;
  cin >> n;
  cin >> k;
  vector<int> v;
  for (int i = 0; i < n; i++) {
    cin >> x;
    v.push_back(x);
  }
  sort(v.begin(), v.end());
  for (int i = 0; i < n; i++) {
    v[i] += k;
  }
  for (int i = 0; i < n; i++) {
    if (v[i] < 5) {
      cnt++;
    }
  }
  int ans = cnt / 3;
  cout << ans << endl;
  return 0;
}
