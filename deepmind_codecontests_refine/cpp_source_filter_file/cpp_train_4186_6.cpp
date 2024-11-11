#include <bits/stdc++.h>
using namespace std;
void solve() {
  long long n;
  cin >> n;
  string s;
  cin >> s;
  long long mini = n - 1, maxi = 0;
  for (long long i = 0; i < n; i++) {
    if (s[i] == '1') {
      mini = i;
      break;
    }
  }
  for (long long i = n - 1; i >= 0; i--) {
    if (s[i] == '1') {
      maxi = i;
      break;
    }
  }
  if (maxi == 0) {
    cout << n << endl;
    return;
  }
  cout << 2 * max(maxi + 1, n - mini) << endl;
}
int main() {
  long long t;
  cin >> t;
  while (t--) solve();
}
