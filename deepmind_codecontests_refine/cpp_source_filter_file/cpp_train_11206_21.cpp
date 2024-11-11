#include <bits/stdc++.h>
using namespace std;
const long long N = 1e9 + 7;
int32_t main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  ;
  long long n, k;
  cin >> n >> k;
  if (k >= 30)
    cout << "No\n";
  else {
    long long flag = 0;
    for (long long i = 1; i <= min((long long)30, k); i++) {
      if ((n + 1) % i != 0) flag = 1;
    }
    if (flag == 0)
      cout << "Yes\n";
    else
      cout << "No\n";
  }
}
