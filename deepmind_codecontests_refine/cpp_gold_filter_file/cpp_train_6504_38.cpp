#include <bits/stdc++.h>
using namespace std;
int main() {
  int n;
  cin >> n;
  vector<int> v(2 << n);
  int size = 2 << n;
  for (int i = (2); i < (int)(size); ++i) cin >> v[i];
  int ans = 0;
  for (int i = size - 1; i >= 2; i -= 2) {
    v[i / 2] += max(v[i], v[i - 1]);
    ans += abs(v[i] - v[i - 1]);
  }
  cout << ans << endl;
  return 0;
}
