#include <bits/stdc++.h>
using namespace std;
int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  long long ans = 0;
  int n;
  cin >> n;
  for (int i = 1; i < n - 1; i++) {
    ans += (i + 1) * (i + 2);
  }
  cout << ans << endl;
}
