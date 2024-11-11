#include <bits/stdc++.h>
using namespace std;
long long int power(long long int x, long long int y) {
  long long int res = 1;
  while (y) {
    if (y & 1) res = (res * x) % 1000000007;
    y = y / 2, x = (x * x) % 1000000007;
  }
  return res % 1000000007;
}
long long int n, m, k;
long long int arr[1000000];
pair<long long int, long long int> lol[1000000];
long long int temp[10000001] = {0};
bool func(long long int index) {
  long long int i;
  long long int tt = index;
  for (i = m - 1; i >= 0; i--) {
    if (index <= 0) break;
    temp[lol[i].first]++;
    index--;
  }
  long long int dr = 0;
  bool ans = true;
  for (i = 0; i <= 10000000; i++) {
    dr += temp[i];
    if ((i + 1) * k < dr) {
      ans = false;
      break;
    }
    if ((i)*k > (n + index)) {
      ans = true;
      break;
    }
  }
  for (i = m - 1; i >= 0; i--) {
    if (tt <= 0) break;
    temp[lol[i].first]--;
    tt--;
  }
  return ans;
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  cin >> n >> m >> k;
  long long int i;
  for (i = 0; i < n; i++) cin >> arr[i], temp[arr[i]]++;
  for (i = 0; i < m; i++) cin >> lol[i].first, lol[i].second = i;
  sort(arr, arr + n);
  sort(lol, lol + m);
  long long int dr = 0;
  for (i = 0; i < n; i++) {
    long long int pos = (arr[i] + 1) * k;
    if (dr >= pos) {
      cout << -1;
      return 0;
    }
    dr++;
  }
  long long int low = 0, high = m;
  long long int ans = 0;
  while (low <= high) {
    long long int mid = (low + high) / 2;
    if (func(mid)) {
      low = mid + 1;
      ans = mid;
    } else
      high = mid - 1;
  }
  cout << ans << "\n";
  for (i = m - 1; i >= 0; i--) {
    if (ans <= 0) break;
    cout << lol[i].second + 1 << " ";
    ans--;
  }
}
