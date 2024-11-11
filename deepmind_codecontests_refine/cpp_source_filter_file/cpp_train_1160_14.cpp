#include <bits/stdc++.h>
using namespace std;
const int N = 1e5 + 7;
int arr[N];
int n;
long long solve(int l, int r) {
  if (l == r) {
    return 1ll * arr[l] * (n - arr[l] + 1);
  }
  int half = (l + r) >> 1;
  int res = solve(l, half) + solve(half + 1, r);
  int L = min(arr[half], arr[half + 1]);
  int R = max(arr[half], arr[half + 1]);
  res -= 1ll * L * (n - R + 1);
  return res;
}
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  cin >> n;
  for (int i = 0; i < n; ++i) {
    cin >> arr[i];
  }
  cout << solve(0, n - 1) << "\n";
  return 0;
}
