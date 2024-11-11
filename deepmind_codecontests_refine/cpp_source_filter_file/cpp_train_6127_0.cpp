#include <bits/stdc++.h>
using namespace std;
using ll = int64_t;
int main() {
  ll s, c;
  cin >> s >> c;
  ll ans = min(s, c / 2);
  s -= ans;
  c -= ans * 2;
  ans += c / 3;
  cout << ans << endl;
}
