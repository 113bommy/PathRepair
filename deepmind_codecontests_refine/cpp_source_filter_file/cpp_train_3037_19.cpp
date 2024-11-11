#include <bits/stdc++.h>
using namespace std;
long long int n, m, ar[1000005], sum, pref[1000005];
int main() {
  cin.tie(0);
  cout.tie(0);
  ios_base::sync_with_stdio(false);
  cin >> n;
  for (int i = 1; i <= n; i++) cin >> ar[i];
  for (int i = 1; i <= n; i++) pref[i] = pref[i - 1] + ar[i];
  cin >> m;
  for (int i = 1; i <= m; i++) {
    long long int a, b;
    cin >> a >> b;
    cout << (pref[b] - pref[a]) / 10 << "\n";
  }
}
