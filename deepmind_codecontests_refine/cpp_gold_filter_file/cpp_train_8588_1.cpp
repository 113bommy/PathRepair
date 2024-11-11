#include <bits/stdc++.h>
using namespace std;
int main() {
  int n;
  cin >> n;
  pair<int, int> a[n];
  for (int i = 0; i < n; i++) cin >> a[i].second >> a[i].first;
  sort(a, a + n);
  int k = a[0].first, ans = 1;
  for (int i = 1; i < n; i++) {
    if (k < a[i].second) {
      ans++;
      k = a[i].first;
    }
  }
  cout << ans;
}
