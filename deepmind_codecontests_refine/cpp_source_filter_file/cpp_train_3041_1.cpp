#include <bits/stdc++.h>
using namespace std;
const int N = 1e5 + 10;
const int M = 1e9 + 7;
bitset<N> bs;
int main() {
  long long n;
  cin >> n;
  long long sum = 0;
  int arr[n];
  for (int i = 0; i < n; i++) {
    cin >> arr[i];
    sum += arr[i];
  }
  long long ans = 0;
  ans += (arr[0] / 2);
  int par = 0;
  for (int i = 1; i < n; i++) {
    if (arr[i] % 2 == (arr[i] + 1) % 2) par = par ^ 1;
    if (par)
      ans += (arr[i] + 1) / 2;
    else
      ans += (arr[i] / 2);
  }
  ans = min(ans, sum - ans);
  cout << ans;
}
