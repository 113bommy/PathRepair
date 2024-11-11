#include <bits/stdc++.h>
using namespace std;
string s, t;
vector<int> can;
int n, m, k;
int main() {
  cin >> n >> m >> k;
  cin >> s >> t;
  for (int i = 0; i <= n - m; i++) {
    if (s.substr(i, m) != t) continue;
    can.push_back(i + 1);
  }
  while (k--) {
    int l, r;
    cin >> l >> r;
    r = r - m + 1;
    int first = lower_bound(can.begin(), can.end(), l) - can.begin();
    int last = upper_bound(can.begin(), can.end(), r) - can.begin();
    cout << max(0, last - first) << endl;
  }
  return 0;
}
