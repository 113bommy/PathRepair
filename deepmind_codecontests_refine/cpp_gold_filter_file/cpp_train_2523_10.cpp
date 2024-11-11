#include <bits/stdc++.h>
using namespace std;
const int PI = 3.14159265;
void fast() {
  std::ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
}
int main() {
  fast();
  int t;
  cin >> t;
  while (t--) {
    long long x, y, a, b;
    cin >> x >> y >> a >> b;
    if (x > y) {
      swap(x, y);
    }
    long long ans1, ans2;
    ans1 = (x + y) * a;
    ans2 = (x * b) + ((y - x) * a);
    cout << min(ans1, ans2) << '\n';
  }
  return 0;
}
