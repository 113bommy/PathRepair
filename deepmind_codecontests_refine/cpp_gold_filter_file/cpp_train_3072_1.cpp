#include <bits/stdc++.h>
using namespace std;
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  vector<pair<long long, long long> > a;
  int n, x1, x2;
  cin >> n >> x1 >> x2;
  for (int i = 1; i <= n; i++) {
    int x, y;
    cin >> x >> y;
    a.push_back({(long long)x * x1 + y, (long long)x * x2 + y});
  }
  sort(a.begin(), a.end());
  for (int i = 1; i < n; i++) {
    if (a[i].second < a[i - 1].second) {
      cout << "YES";
      return 0;
    }
  }
  cout << "NO";
}
