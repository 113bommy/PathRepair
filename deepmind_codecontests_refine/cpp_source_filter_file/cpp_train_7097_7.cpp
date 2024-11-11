#include <bits/stdc++.h>
using namespace std;
void solve() {
  long long ans = 0;
  long long n;
  cin >> n;
  vector<long long> v(n);
  int neg = 0, pos = 0, z = 0;
  for (int i = 0; i < (n); i += 1) {
    int num;
    cin >> num;
    if (num >= 1) {
      ans += num - 1;
      v[i] = 1;
      pos++;
    } else if (num <= -1) {
      ans += -(num + 1);
      v[i] = -1;
      neg++;
    } else {
      z++;
    }
  }
  if (z) {
    ans += z;
  } else if (neg) {
    ans += 2;
  }
  cout << ans << "\n";
  ;
}
int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  solve();
  return 0;
}
