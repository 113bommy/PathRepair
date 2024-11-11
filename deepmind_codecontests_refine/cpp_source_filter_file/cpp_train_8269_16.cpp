#include <bits/stdc++.h>
using namespace std;
const int maxn = 100100;
int n;
pair<int, int> a[maxn];
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cin >> n;
  for (int i = 0; i < n; i++) cin >> a[i].first >> a[i].second;
  sort(a, a + n);
  for (int i = 0; i < n - 1; i++) {
    if (a[i - 1].first < a[i].first && a[i - 1].second > a[i].second) {
      cout << "Happy Alex";
      return 0;
    }
  }
  cout << "Poor Alex";
  return 0;
}
