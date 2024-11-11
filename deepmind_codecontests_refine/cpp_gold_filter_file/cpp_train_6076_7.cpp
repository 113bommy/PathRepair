#include <bits/stdc++.h>
using namespace std;
int n, h;
pair<int, int> a[100005];
int ans[100005];
int good[2];
int main() {
  cin >> n >> h;
  for (int i = 0; i < n; i++) {
    int temp;
    cin >> temp;
    a[i].first = temp;
    a[i].second = i;
  }
  sort(a, a + n);
  fill(good, good + 2, 1000000000);
  good[0] = a[n - 2].first + a[n - 1].first - a[0].first - a[1].first;
  if (n > 2) {
    good[1] =
        max(a[n - 2].first + a[n - 1].first, a[0].first + a[n - 1].first + h) -
        min(a[1].first + a[2].first, a[0].first + a[1].first + h);
  }
  for (int i = 0; i < n; i++) ans[i] = 1;
  if (good[0] < good[1]) {
    cout << good[0] << endl;
  } else {
    ans[a[0].second] = 2;
    cout << good[1] << endl;
  }
  for (int i = 0; i < n; i++) cout << ans[i] << " ";
  return 0;
}
