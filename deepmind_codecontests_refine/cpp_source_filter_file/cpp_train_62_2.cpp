#include <bits/stdc++.h>
using namespace std;
int main() {
  cout << fixed << setprecision(10);
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  long long int n, d;
  cin >> n >> d;
  long long int a[n], b[n];
  for (long long int i = 0; i < n; i++) {
    cin >> a[i];
    b[i] = (i ? b[i - 1] + a[i] : a[i]);
    if (b[i] > d) {
      cout << -1;
      return 0;
    }
  }
  long long int maxi[n + 1];
  maxi[n] = 0;
  maxi[n - 1] = b[n - 1];
  for (long long int i = n - 2; i >= 0; i--) maxi[i] = max(b[i], maxi[i + 1]);
  long long int added = 0, ans = 0;
  if (a[0] == 0 && b[0] < 0) {
    added += d - maxi[0];
    if (b[0] + added < 0) {
      cout << -1;
      return 0;
    }
    ++ans;
  }
  for (long long int i = 1; i < n; i++) {
    b[i] += added;
    if (a[i] == 0 && b[i] < 0) {
      long long int here = d - maxi[i] - added;
      added += here;
      ++ans;
      b[i] += added;
      if (b[i] < 0) {
        cout << -1;
        return 0;
      }
    }
  }
  cout << ans;
}
