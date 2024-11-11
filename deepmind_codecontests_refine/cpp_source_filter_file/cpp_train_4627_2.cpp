#include <bits/stdc++.h>
using namespace std;
int main() {
  int n, r;
  cin >> n >> r;
  int a[n];
  for (int i = 0; i < n; i++) {
    cin >> a[i];
  }
  int ret = r;
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < n; j++) {
      ret = max(ret, r / a[i] * a[j] + r % a[i]);
    }
  }
  cout << ret << endl;
  return 0;
}
