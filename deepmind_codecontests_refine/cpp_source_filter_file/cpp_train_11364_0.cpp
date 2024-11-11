#include <bits/stdc++.h>
using namespace std;
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  ;
  long long n;
  cin >> n;
  long long ar[n + 10];
  for (int i = 0; i < n; i++) cin >> ar[i];
  long long ans = ar[0];
  for (int i = 1; i <= n - 1; i++)
    ans = min(ans, ar[i] / (max((long long)i, n - 1 - (long long)i)));
  cout << ans << endl;
  ;
  return 0;
}
