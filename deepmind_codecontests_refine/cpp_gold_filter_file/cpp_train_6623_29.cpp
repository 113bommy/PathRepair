#include <bits/stdc++.h>
using namespace std;
int main() {
  vector<long long int> vec;
  long long int n, i, j, k, x, y, t, m;
  cin >> n >> k >> x;
  for (i = 0; i < n; i++) {
    cin >> y;
    vec.push_back(y);
  }
  reverse(vec.begin(), vec.end());
  long long int ans = 0;
  for (i = 0; i < k; i++) ans += x;
  for (i = k; i < n; i++) ans += vec[i];
  cout << ans << endl;
}
