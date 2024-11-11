#include <bits/stdc++.h>
using namespace std;
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  ;
  long long int n, k, x;
  cin >> n >> k >> x;
  long long int ans = 0;
  for (long long int i = 0; i < n; i++) {
    long long int v;
    cin >> v;
    if (i < (n - k))
      ans += v;
    else
      ans += x;
  }
  cout << ans;
}
