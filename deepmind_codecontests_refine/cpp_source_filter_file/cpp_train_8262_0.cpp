#include <bits/stdc++.h>
using namespace std;
map<int, int> m;
int a[1001];
int main() {
  int n;
  cin >> n;
  for (int i = 1; i <= n; i++) {
    cin >> a[i];
    m[a[i]]++;
  }
  int ans = 0;
  for (int i = 1; i <= n; i++) {
    if (a[i] != 0 && m[a[i]] == 2) {
      ans++;
    }
    if (m[a[i]] > 2 && a[i] != 0) {
      cout << -1;
      return 0;
    }
  }
  cout << ans;
}
