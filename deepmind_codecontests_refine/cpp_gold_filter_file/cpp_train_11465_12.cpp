#include <bits/stdc++.h>
using namespace std;
using ll = long long int;
using pii = pair<int, int>;
using pll = pair<ll, ll>;
using maxHeap = priority_queue<int>;
using minHeap = priority_queue<int, vector<int>, greater<int>>;
int main() {
  ios::sync_with_stdio(0), cin.tie(0);
  int t, x;
  double d, p;
  cout << fixed << setprecision(10);
  for (cin >> t; t; t--) {
    cin >> x;
    d = x;
    if (x * x - 4 * x < 0) {
      cout << "N\n";
    } else {
      p = sqrt(d * d - 4 * d);
      cout << "Y " << (d - p) / 2 << ' ' << (d + p) / 2 << '\n';
    }
  }
  return 0;
}
