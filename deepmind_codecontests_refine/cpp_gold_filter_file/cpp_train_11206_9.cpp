#include <bits/stdc++.h>
using namespace std;
vector<long long> v;
int32_t main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  ;
  long long n, k, arr[1000001] = {};
  cin >> n >> k;
  for (long long i = 1; i <= min((long long)100000, k); i++) {
    if (arr[n % i]) {
      cout << "No";
      return 0;
    }
    arr[n % i]++;
  }
  cout << "Yes";
}
