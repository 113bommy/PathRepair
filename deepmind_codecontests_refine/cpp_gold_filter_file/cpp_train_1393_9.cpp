#include <bits/stdc++.h>
using namespace std;
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  int n;
  cin >> n;
  int total = 0;
  for (int i = 0; i < n; i++) {
    int x;
    cin >> x;
    total = total + x;
  }
  int ans = 0;
  for (int i = 1; i < 6; i++) {
    if ((total + i) % (n + 1) != 1) ans++;
  }
  cout << ans;
}
