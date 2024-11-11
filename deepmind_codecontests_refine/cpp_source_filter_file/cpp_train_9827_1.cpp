#include <bits/stdc++.h>
using namespace std;
const int mod = 1e9 + 7;
int power(int x, int a, int b) {
  if (a <= 0) return (1);
  long long z = power(x, a / 2, b);
  z = (z * z) % b;
  if (a % 2) z = (z * x) % b;
  return (z);
}
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  int n;
  cin >> n;
  vector<long long> arr(n + 1);
  for (int i = 1; i <= n; i++) {
    cin >> arr[i];
  }
  sort(arr.begin(), arr.end(), greater<long long>());
  vector<long long> pfx_sum(n + 1);
  for (int i = 1; i <= n; i++) {
    pfx_sum[i] = pfx_sum[i - 1] + arr[i];
  }
  long long beauty;
  for (int val = 1; val <= n; val *= 4) {
    beauty += (pfx_sum[val]);
  }
  cout << beauty << endl;
}
