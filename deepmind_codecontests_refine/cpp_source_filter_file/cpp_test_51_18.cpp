#include <bits/stdc++.h>
using namespace std;
template <typename T>
ostream& operator<<(ostream& os, vector<T>& v) {
  for (auto element : v) {
    os << element << ' ';
  }
  return os;
}
void solve() {
  long long n;
  cin >> n;
  long long l, r;
  l = -1 * (n - 1);
  r = n;
  cout << l << r << '\n';
}
using namespace std;
int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  long long t;
  cin >> t;
  while (t > 0) {
    solve();
    t--;
  }
  return 0;
}
