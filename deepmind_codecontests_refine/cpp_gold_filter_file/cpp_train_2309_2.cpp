#include <bits/stdc++.h>
using namespace std;
int main() {
  cin.tie(0);
  ios_base::sync_with_stdio(0);
  int n;
  cin >> n;
  int ans = 0;
  int max = 150001;
  int a[n];
  bool onTeam[max + 1];
  fill(onTeam, onTeam + max + 1, false);
  for (int i = 0; i < n; i++) {
    cin >> a[i];
  }
  sort(a, a + n);
  for (int i = n - 1; i >= 0; i--) {
    if (a[i] + 1 <= max && onTeam[a[i] + 1] == false) {
      onTeam[a[i] + 1] = true;
      ans++;
    } else if (onTeam[a[i]] == false) {
      onTeam[a[i]] = true;
      ans++;
    } else if (a[i] - 1 > 0 && onTeam[a[i] - 1] == false) {
      onTeam[a[i] - 1] = true;
      ans++;
    }
  }
  cout << ans;
  return 0;
}
