#include <bits/stdc++.h>
using namespace std;
const int MAXN = 1e5 + 100;
int arr[MAXN];
int n, x, t;
long long ans;
int main() {
  cin >> n;
  for (int i = 0; i < n; i++) {
    cin >> x;
    if (t <= 1)
      arr[++t] = x;
    else {
      while (t > 1 && arr[t] <= arr[t - 1] && arr[t] <= x) {
        ans += min(arr[t - 1], x);
        t--;
      }
      arr[++t] = x;
    }
  }
  sort(arr, arr + t, greater<int>());
  for (int i = 3; i <= t; i++) ans += arr[i];
  return cout << ans << endl, 0;
}
