#include <bits/stdc++.h>
using namespace std;
const int N = 200010;
vector<vector<int> > p;
int main() {
  int a, b, c, n, x, ans = 0;
  cin >> a >> b >> c;
  cin >> n;
  while (n--) {
    cin >> x;
    if (b < x && x < a) ans++;
  }
  cout << ans << endl;
  return 0;
}
