#include <bits/stdc++.h>
using namespace std;
long long arr[300001], arr1[300001];
int main() {
  long long n, res = 9999999999999;
  cin >> n;
  for (int i = 0; i < n; i++) {
    cin >> arr[i];
  }
  for (long long i = 0; i < n; i++) {
    res = min(res, arr[i] / max(i, n - i));
  }
  cout << res;
}
