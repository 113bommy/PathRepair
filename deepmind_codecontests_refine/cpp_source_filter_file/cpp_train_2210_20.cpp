#include <bits/stdc++.h>
using namespace std;
int arr1[11], arr2[11];
int main() {
  int n;
  cin >> n;
  int z = 0;
  for (int i = 0; i < n; i++) {
    int t;
    cin >> t;
    if (!t) {
      z++;
    } else if (t < 0) {
      arr1[-t]++;
    } else {
      arr2[t]++;
    }
  }
  unsigned long long int ans = 0;
  z--;
  ans += (unsigned long long)(z * (z + 1)) / 2;
  for (int i = 0; i < 11; i++) {
    ans += (unsigned long long)arr1[i] * arr2[i];
  }
  cout << ans;
  return 0;
}
