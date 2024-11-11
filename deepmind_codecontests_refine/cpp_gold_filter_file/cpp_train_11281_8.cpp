#include <bits/stdc++.h>
using namespace std;
int main() {
  cout << fixed;
  cout.precision(9);
  int t;
  cin >> t;
  while (t-- > 0) {
    int n;
    cin >> n;
    vector<pair<pair<long, long>, int> > b;
    for (int i = 0; i < 2 * n - 1; i++) {
      long x, y;
      cin >> x >> y;
      b.push_back(make_pair(make_pair(x, y), i + 1));
    }
    sort(b.begin(), b.end());
    long long s1 = 0, s2 = 0;
    for (int i = 0; i < 2 * n - 1; i += 2) {
      s1 += b[i].first.second;
    }
    for (int i = 1; i < 2 * n - 1; i += 2) {
      s2 += b[i].first.second;
    }
    cout << "YES\n";
    if (s1 >= s2) {
      for (int i = 0; i < 2 * n - 1; i += 2) cout << b[i].second << " ";
    } else {
      for (int i = 1; i < 2 * n - 1; i += 2) cout << b[i].second << " ";
      cout << b[2 * n - 2].second;
    }
    cout << "\n";
  }
  return 0;
}
