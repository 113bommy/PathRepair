#include <bits/stdc++.h>
using namespace std;
int main() {
  cin.tie(0), cout.tie(0), cin.sync_with_stdio(0), cout.sync_with_stdio(0);
  int t;
  cin >> t;
  while (t--) {
    int n, s, c, sum = 0;
    cin >> n >> s;
    vector<int> v;
    for (int i = 0; i < n; ++i) {
      cin >> c;
      v.push_back(c);
    }
    c = 0;
    int mx = INT_MIN;
    for (int i = 0; i < v.size(); ++i) {
      if (sum <= s) {
        if (v[i] > mx) {
          mx = v[i];
          c = i + 1;
        }
        sum += v[i];
      }
    }
    if (sum <= s) {
      cout << 0 << endl;
    } else {
      cout << c << endl;
    }
  }
}
