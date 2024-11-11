#include <bits/stdc++.h>
using namespace std;
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  int t;
  cin >> t;
  while (t--) {
    int n, k;
    cin >> n >> k;
    vector<long long> a;
    for (int e = 0; e < n; e++) {
      long long y;
      cin >> y;
      a.push_back(y);
    };
    set<long long> s;
    long long sum = 0, prev = -1, j = 0;
    for (int i = 0; i < n; i++) {
      s.insert(a[i]);
    }
    if (s.size() <= k) {
      cout << 1 << "\n";
    } else if (k > 1) {
      cout << 1 + ceil((double)(s.size() - k) / (k - 1)) << "\n";
    } else {
      cout << -1 << "\n";
    }
  }
}
