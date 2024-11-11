#include <bits/stdc++.h>
using namespace std;
long long n, m, k, mi, ans = 0;
vector<long long> arr;
int main() {
  cin >> n >> m >> k;
  arr.resize(n);
  for (int i = 0; i < n; i++) cin >> arr[i];
  sort(arr.begin(), arr.end());
  mi = (m / (k + 1));
  if (m % (k + 1) == 0) {
    ans += arr[arr.size() - 1] * k * mi;
    ans += arr[arr.size() - 2] * mi;
    cout << ans;
  } else {
    ans += arr[arr.size() - 1] * k * mi;
    ans += arr[arr.size() - 2] * mi;
    ans += arr[arr.size() - 1] * (m % (k + 1));
    cout << ans;
  }
}
