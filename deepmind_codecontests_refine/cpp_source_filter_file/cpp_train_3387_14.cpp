#include <bits/stdc++.h>
using namespace std;
const int mod = 1e9 + 7;
const long long int maxn = 1e6 + 1;
double pie = 3.1415926535;
long long int a[maxn];
long long int n, k;
bool solve(long long int x) {
  long long int ans = 1e9, i, cnt = 0;
  for (i = 0; i < x; i++) {
    if (a[i] == 0) cnt++;
  }
  ans = cnt;
  for (i = x; i < n; i++) {
    if (a[i] == 0) cnt++;
    if (a[i - x] == 0) cnt--;
    ans = min(ans, cnt);
  }
  if (ans <= k) return true;
  return false;
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  long long int i, ans, j;
  cin >> n >> k;
  for (i = 0; i < n; i++) {
    cin >> a[i];
  }
  long long int low = 0, high = n - 1;
  while (low <= high) {
    long long int mid = (low + high) / 2;
    if (solve(mid)) {
      low = mid + 1;
      ans = mid;
    } else {
      high = mid - 1;
    }
  }
  cout << ans << endl;
  long long int cnt = 0, idx;
  for (i = 0; i < ans; i++) {
    if (a[i] == 0) cnt++;
  }
  if (cnt <= k) idx = i - 1;
  for (i = ans; i < n; i++) {
    if (a[i] == 0) cnt++;
    if (a[i - ans] == 0) cnt--;
    if (cnt <= k) {
      idx = i;
      break;
    }
  }
  idx = idx - ans + 1;
  for (i = 0; i < idx; i++) {
    cout << a[i] << " ";
  }
  for (j = idx, cnt = 0; cnt < ans; j++, cnt++)
    cout << "1"
         << " ";
  for (j = idx + ans; j < n; j++) cout << a[j] << " ";
}
