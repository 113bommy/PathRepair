#include <bits/stdc++.h>
using namespace std;
using namespace std;
int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  long long n, MAX = INT_MIN, MIN = INT_MAX;
  cin >> n;
  long long a[n], ma = 0, mb = 0, i;
  for (i = 0; i < n; i++) {
    cin >> a[i];
    if (a[i] >= MAX) {
      MAX = max(MAX, a[i]);
      ma = i;
    }
    if (a[i] <= MIN) {
      MIN = min(MIN, a[i]);
      mb = i;
    }
  }
  n--;
  if (ma > mb)
    cout << ma + n - mb - 1 << endl;
  else
    cout << n + ma - mb << endl;
}
