#include <bits/stdc++.h>
using namespace std;
pair<int, int> arr[200005];
int main() {
  int n;
  cin >> n;
  for (int i = 0; i <= n; i++) cin >> arr[i].first >> arr[i].second;
  int ans = 0;
  int ant =
      (arr[1].first - arr[0].first) * (arr[0].second - arr[n - 2].second) -
      (arr[1].second - arr[0].second) * (arr[0].first - arr[n - 2].first);
  if (ant >= 1)
    ant = 1;
  else
    ant = -1;
  for (int i = 1; i <= n - 1; i++) {
    int y =
        (arr[i].first - arr[i - 1].first) *
            (arr[i + 1].second - arr[i].second) -
        (arr[i].second - arr[i - 1].second) * (arr[i + 1].first - arr[i].first);
    if (ant * (y) > 0) ans++;
  }
  cout << ans << endl;
}
