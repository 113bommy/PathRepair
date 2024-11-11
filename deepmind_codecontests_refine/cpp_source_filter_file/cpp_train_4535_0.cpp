#include <bits/stdc++.h>
using namespace std;
signed main() {
  long long a;
  cin >> a;
  long long arr[a];
  for (long long i = 0; i < a; i++) cin >> arr[i];
  sort(arr, arr + a);
  cout << arr[a / 2 - 1] << endl;
  return 0;
}
