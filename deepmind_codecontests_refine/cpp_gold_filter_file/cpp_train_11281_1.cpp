#include <bits/stdc++.h>
using namespace std;
const int maxx = 2e6 + 20;
pair<pair<long long, long long>, long long> a[maxx];
int main() {
  ios::sync_with_stdio(false);
  long long t;
  cin >> t;
  for (int i = 0; i < t; i++) {
    long long n;
    cin >> n;
    int m = 2 * n - 1;
    for (int j = 0; j < m; j++) {
      cin >> a[j].first.first >> a[j].first.second;
      a[j].second = j;
    }
    sort(a, a + m);
    cout << "YES\n";
    for (int j = 0; j < m - 2; j += 2) {
      if (a[j].first.second <= a[j + 1].first.second)
        cout << a[j + 1].second + 1 << " ";
      else
        cout << a[j].second + 1 << " ";
    }
    cout << a[m - 1].second + 1 << " ";
    cout << "\n";
  }
}
