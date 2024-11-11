#include <bits/stdc++.h>
using namespace std;

int main() {
  int n;
  cin >> n;
  vector<long> a(n), s(n + 1);
  for (int i = 0; i < n; i++) {
    cin >> a.at(i);
    s.at(i + 1) = s.at(i) + a.at(i);
  }
  long ans = s.at(n);
  for (int i = 0; i < n; i++) {
    ans = min(ans, abs(2 * s.at(i) - s.at(n)));
  }
  cout << ans << endl;
}
