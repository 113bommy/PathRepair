#include <bits/stdc++.h>
using namespace std;
void fastInput() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
}
int main() {
  fastInput();
  long long n;
  cin >> n;
  int arr[n];
  long long mx = -1, mn = 1e12;
  for (int i = 0; i < n; i++) cin >> arr[i];
  for (int i = 0; i < n; i++) {
    if (arr[i] > mx) mx = arr[i];
    if (arr[i] < mn) mn = arr[i];
  }
  if (mn == mx) {
    cout << 0 << " ";
    long long ans = (n * (n - 1)) / 2;
    cout << ans;
  } else {
    long long c = 0, c1 = 0;
    for (int i = 0; i < n; i++) {
      if (arr[i] == mx) c++;
      if (arr[i] == mn) c1++;
    }
    cout << mx - mn << " " << c * c1;
  }
  return 0;
}
