#include <bits/stdc++.h>
using namespace std;
void run_code_sublimetext3() {}
long long n, A[1000100];
int32_t main() {
  run_code_sublimetext3();
  ios_base::sync_with_stdio(false);
  cin >> n;
  long long k = sqrt(n);
  long long ans = k * 4;
  if (n == k * k)
    cout << ans;
  else if (n - k * k <= k)
    cout << ans + 2;
  else
    cout << ans + 4;
}
