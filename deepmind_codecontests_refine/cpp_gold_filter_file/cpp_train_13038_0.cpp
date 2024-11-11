#include <bits/stdc++.h>
using namespace std;
int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int t;
  cin >> t;
  while (t--) {
    long long int n, m;
    cin >> n >> m;
    long long int ans1, ans2;
    long long int temp1 = m / 2, temp2 = n / 2;
    ans1 = n * temp1;
    if (m % 2 != 0) ans1 += (n + 1) / 2;
    ans2 = m * temp2;
    if (n % 2 != 0) ans2 += (m + 1) / 2;
    cout << min(ans1, ans2) << "\n";
  }
  return 0;
}
