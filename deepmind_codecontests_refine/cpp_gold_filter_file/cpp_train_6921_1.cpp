#include <bits/stdc++.h>
using namespace std;
int t[100005];
int main() {
  int n;
  cin >> n;
  for (int i = 0; i < n; i++) {
    cin >> t[i];
  }
  sort(t, t + n);
  int ans = 0;
  long long s = 0;
  for (int i = 0; i < n; i++) {
    if (s <= t[i]) {
      ans++;
      s += t[i];
    }
  }
  cout << ans << endl;
  return 0;
}
