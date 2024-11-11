#include <bits/stdc++.h>
using namespace std;
const long long N = 1e7 + 5;
const long long MOD = 1000000007;
int32_t main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  ;
  long long n;
  cin >> n;
  string str;
  cin >> str;
  long long arr1[n], arr2[n];
  for (long long i = 0; i < n; i++) {
    arr1[i] = str[i] - '0';
    arr2[i] = str[n + i] - '0';
  }
  sort(arr1, arr1 + n);
  sort(arr2, arr2 + n);
  bool lessThan = true, moreThan = true;
  long long i = 0, j = n - 1;
  for (long long i = 0; i < n; i++) {
    if (arr1[i] >= arr2[i]) lessThan = false;
  }
  for (long long i = 0; i < n; i++) {
    if (arr1[i] <= arr2[i]) moreThan = false;
  }
  if (lessThan || moreThan) {
    cout << "YES"
         << "\n";
  } else {
    cout << "NO"
         << "\n";
  }
}
