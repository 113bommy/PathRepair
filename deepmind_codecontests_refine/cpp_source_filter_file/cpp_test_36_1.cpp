#include <bits/stdc++.h>
using namespace std;
bool isPrime(int n) {
  for (int i = 2; i * i < n; i++) {
    if (n % i == 0) return false;
  }
  return true;
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  ;
  long long test = 1;
  cin >> test;
  while (test--) {
    int n;
    cin >> n;
    int sum = 0;
    vector<int> arr(n);
    int index = -1;
    for (int i = 0; i < n; i++) {
      cin >> arr[i];
      sum += arr[i];
      if (arr[i] % 2) index = i;
    }
    int ans = n;
    if (isPrime(sum)) {
      sum -= arr[index];
      arr[index] = -1;
      ans--;
    }
    cout << ans << "\n";
    for (int i = 0; i < n; i++) {
      if (arr[i] != -1) {
        cout << i + 1 << " ";
      }
    }
    cout << "\n";
  }
}
