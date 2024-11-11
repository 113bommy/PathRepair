#include <bits/stdc++.h>
using namespace std;
const long long mod = 1000000007;
void solve() {
  long long n, s;
  cin >> n >> s;
  long long arr[n];
  long long sum = 0;
  for (int i = 0; i < n; i++) {
    cin >> arr[i];
    sum += arr[i];
  }
  if (sum <= s) {
    cout << 0 << endl;
    return;
  }
  sum = 0;
  int idx;
  for (int i = 0; i < n; i++) {
    sum += arr[i];
    if (sum > s) {
      idx = i;
      break;
    }
  }
  long long maxidx;
  long long maxx = INT_MIN;
  for (int i = 0; i <= idx; i++) {
    if (arr[i] > maxx) {
      maxx = arr[i];
      maxidx = i;
    }
  }
  cout << maxidx + 1 << endl;
}
int main() {
  { ios_base::sync_with_stdio(false); }
  { cin.tie(NULL); }
  cout << setprecision(15) << fixed;
  long long t;
  cin >> t;
  while (t--) {
    solve();
  }
}
