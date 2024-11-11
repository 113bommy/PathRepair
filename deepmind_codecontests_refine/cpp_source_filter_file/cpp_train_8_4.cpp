#include <bits/stdc++.h>
using namespace std;
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  int n;
  cin >> n;
  string a;
  cin >> a;
  int ans = 0;
  for (int i = 0; i < n; ++i) {
    ans += (a[i] == '8');
  }
  cout << min(ans, n / 8) << "\n";
}
