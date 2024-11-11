#include <bits/stdc++.h>
using namespace std;
int const MAXN = 2 * 1000 * 100 + 10;
pair<pair<long long, long long>, int> a[MAXN];
int main() {
  int t, n;
  cin >> t;
  for (int i = 0; i < t; i++) {
    cin >> n;
    long long ora = 0;
    for (int j = 1; j < 2 * n; j++) {
      cin >> a[j].first.first >> a[j].first.second;
      a[j].second = j;
      ora += a[j].first.second;
    }
    sort(a + 1, a + 2 * n);
    long long ko = 0;
    for (int j = 1; j < 2 * n; j += 2) {
      ko += a[j].first.second;
    }
    if (ko * 2 >= ora) {
      cout << "YES"
           << "\n";
      for (int j = 1; j < 2 * n; j += 2) {
        cout << a[j].second << " ";
      }
      cout << "\n";
    } else {
      cout << "YES"
           << "\n";
      for (int j = 2; j < 2 * n; j += 2) {
        cout << a[j].second << " ";
      }
      cout << a[2 * n - 1].second;
      cout << "\n";
    }
  }
  return 0;
}
