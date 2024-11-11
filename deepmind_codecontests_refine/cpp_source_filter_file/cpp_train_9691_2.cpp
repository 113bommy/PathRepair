#include <bits/stdc++.h>
const long long max9 = 10 + 1e9, max6 = 10 + 1e6, max12 = 10 + 1e12,
                max15 = 10 + 1e15;
const long long min6 = -1 * max6, min9 = -1 * max9, min12 = -1 * max12,
                min15 = -1 * max15;
const long long R = 7 + 1e9, NN = 10 + 1e5;
using namespace std;
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  long long n, d, ans = 0;
  cin >> n >> d;
  long long a[n];
  for (int i = (0); i < (n); ++i) cin >> a[i];
  for (int i = (0); i < (n - 1); ++i) {
    if (a[i + 1] - a[i] > 2 * d)
      ans += 2;
    else if (a[i + 1] - a[i] > d)
      ans++;
  }
  cout << ans + 1;
  return 0;
}
