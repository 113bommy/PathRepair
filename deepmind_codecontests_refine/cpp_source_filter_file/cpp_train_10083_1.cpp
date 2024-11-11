#include <iostream>
#include <algorithm>
using namespace std;
typedef long long ll;
int main(void) {
  int n
  ll a, b;
  cin >> n >> a >> b;
  ll l, r;
  cin >> l;
  ll ans = 0;
  for (int i = 1; i < n; i++) {
    cin >> r;
    ans += min((r - l) * a, b);
    l = r;
  }
  cout << ans << endl;
  return 0;
}