#include <bits/stdc++.h>
using namespace std;
long long hcf(long long n1, long long n2) {
  if (n2 != 0)
    return hcf(n2, n1 % n2);
  else
    return n1;
}
int gcd(int a, int b) {
  if (b == 0) return a;
  return gcd(b, a % b);
}
long long findlcm(int arr[], int n) {
  long long ans = arr[0];
  for (int i = 1; i < n; i++) ans = (((arr[i] * ans)) / (hcf(arr[i], ans)));
  return ans;
}
int main() {
  int t;
  cin >> t;
  while (t--) {
    int a, b, c, d;
    cin >> a >> b >> c >> d;
    int ans = max((a + b), (c + d));
    cout << ans << endl;
  }
  return 0;
}
