#include <bits/stdc++.h>
using namespace std;
long double n, val, pre, ans;
unordered_map<long double, long double> m;
int main() {
  ios::sync_with_stdio(false);
  cin >> n;
  for (int i = (1); i <= (n); i++) {
    cin >> val;
    long double ignore = m[val] + m[val - 1] + m[val + 1];
    long double ignVal =
        m[val] * val + m[val - 1] * (val - 1) + m[val + 1] * (val + 1);
    long double bef = i - 1 - ignore;
    ans += bef * val - (pre - ignVal);
    pre += val;
    m[val]++;
  }
  cout << setprecision(0) << fixed << ans;
}
