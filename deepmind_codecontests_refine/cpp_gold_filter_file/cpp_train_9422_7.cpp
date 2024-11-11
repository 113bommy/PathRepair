#include <bits/stdc++.h>
using namespace std;
int main() {
  long long int n, ans = 0, arr[100010] = {};
  cin >> n;
  long long int x;
  for (int i = 0; i < n; i++) {
    cin >> x;
    arr[x] = arr[x - 1] + 1;
    ans = max(ans, arr[x]);
  }
  cout << n - ans;
  return 0;
}
