#include <bits/stdc++.h>
long long minn = INT_MAX;
long long maxx = INT_MAX;
using namespace std;
signed main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  long long n;
  cin >> n;
  long long even, odd;
  if (n % 2 != 0) {
    odd = 1;
    n = n - 3;
    cout << "7";
  }
  even = odd / 2;
  for (long long i = 0; i < even; i++) cout << "2";
  return 0;
}
