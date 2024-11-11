#include <bits/stdc++.h>
using namespace std;
int dx[] = {0, 1, 0, -1};
int dy[] = {1, 0, -1, 0};
string blank = "";
const int N = 2e5 + 10;
vector<double> arr(N);
int n;
vector<double> ans(3);
bool can(double mid) {
  int j = 0;
  double p = arr[0] + mid + mid;
  for (int i = 0; i < 3; i++) {
    ans[i] = p - mid;
    for (;; j++) {
      if (j >= n) return true;
      if (arr[j] > p) break;
    }
    p = arr[j] + mid + mid;
  }
  return false;
}
void solve() {
  cin >> n;
  for (long long i = (0); i < (n); i++) cin >> arr[i];
  sort(arr.begin(), arr.begin() + n);
  double l = 0, r = arr[n - 1] - arr[0], mid;
  int rep = 100;
  while (rep--) {
    mid = l + ((r - l) / 2.0);
    if (can(mid))
      r = mid;
    else
      l = mid;
  }
  cout << fixed << setprecision(6) << l << '\n';
  for (long long i = (0); i < (3); i++)
    cout << fixed << setprecision(6) << ans[i] << " ";
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  solve();
}
