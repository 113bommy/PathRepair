#include <bits/stdc++.h>
using namespace std;
const int Maxn = 100 * 1000 + 10;
int n, k, arr[Maxn], ans1, ans2;
int main() {
  cin >> n >> k;
  for (int i = 0; i < n; i++) cin >> arr[i];
  sort(arr, arr + n);
  int pt = n - 1, kp = k;
  for (int i = n - 1; i >= 0; i--) {
    if (kp - (arr[n - 1] - arr[i]) >= 0) {
      pt = i;
      kp -= arr[n - 1] - arr[i];
    }
  }
  ans1 = n - pt, ans2 = arr[n - 1];
  for (int i = n - 2; i >= 0; i--) {
    if (pt > i)
      pt = i, kp = k;
    else
      kp += (i + 2 - pt) * (arr[i + 1] - arr[i]);
    while (pt >= 0 && kp - (arr[i] - arr[pt]) >= 0)
      kp -= arr[i] - arr[pt], pt--;
    pt++;
    if (i + 1 - pt >= ans1) {
      ans1 = i + 1 - pt;
      ans2 = arr[i];
    }
  }
  cout << ans1 << " " << ans2 << endl;
  return 0;
}
