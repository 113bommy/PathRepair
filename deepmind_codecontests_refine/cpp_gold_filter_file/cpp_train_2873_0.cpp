#include <bits/stdc++.h>
using namespace std;
long long int mod = 1e9 + 7;
int main() {
  int n;
  cin >> n;
  long long int x, num[n], arr[n + 1], sum = 0;
  arr[0] = 1;
  for (int i = 0; i < n; i++) {
    cin >> x;
    num[i] = x;
    arr[i + 1] = (arr[i] * 2) % mod;
  }
  sort(num, num + n);
  for (int i = 0; i < n; i++) {
    sum += (num[i] * (arr[i] - arr[n - i - 1])) % mod;
    sum %= mod;
  }
  cout << sum % mod << endl;
}
