#include <bits/stdc++.h>
using namespace std;
int n, h;
vector<int> arr;
bool canPut(int k) {
  vector<int> sorted(arr.begin(), arr.begin() + k);
  sort(sorted.rbegin(), sorted.rend());
  long long sum = 0;
  for (int i = 0; i < k; i += 2) sum += sorted[i];
  return sum <= h;
}
int main() {
  ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);
  cin >> n >> h;
  arr.resize(n);
  for (auto &value : arr) cin >> value;
  int lo = 1, hi = n, mid, ans = 0;
  while (lo <= hi) {
    mid = lo + (hi - lo) / 2;
    if (canPut(mid)) {
      ans = mid;
      lo = mid + 1;
    } else
      hi = mid - 1;
  }
  cout << ans << endl;
  return 0;
}
