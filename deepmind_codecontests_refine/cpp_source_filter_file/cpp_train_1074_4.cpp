#include <bits/stdc++.h>
using namespace std;
int main() {
  vector<int> vec;
  double ans = 0;
  int n;
  cin >> n;
  vec.resize(n);
  for (int i = 0; i < n; cin >> vec[i++])
    ;
  sort(vec.begin(), vec.end());
  for (int i = 0; i < n; i += 2) ans += vec[i] * vec[i];
  for (int i = 1; i < n; i += 2) ans -= vec[i] * vec[i];
  ans *= 3.1415926536;
  cout << fixed << setprecision(11) << ans << endl;
  return 0;
}
