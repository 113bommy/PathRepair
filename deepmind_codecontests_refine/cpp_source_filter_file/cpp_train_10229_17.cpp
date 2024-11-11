#include <bits/stdc++.h>
using namespace std;
int gcd(int a, int b) {
  int c = a % b;
  while (c != 0) {
    a = b;
    b = c;
    c = a % b;
  }
  return b;
}
int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  int t;
  cin >> t;
  while (t--) {
    long long int a, b, n;
    cin >> a >> b >> n;
    long long int count = 0, sum = 0, flag = 0;
    long long int arr[2];
    arr[0] = max(a, b);
    arr[1] = min(a, b);
    while (sum <= n) {
      count++;
      if (flag == 0) {
        sum = arr[0] + arr[1];
        arr[0] = arr[0] + arr[1];
        flag = 1;
      } else {
        sum = arr[0] + arr[1];
        arr[1] = arr[0] + arr[1];
        flag = 0;
      }
    }
    cout << count << "\n";
  }
  return 0;
}
