#include <bits/stdc++.h>
using namespace std;
int a[101];
int main() {
  int n;
  cin >> n;
  for (int i = 0; i < n; i++) cin >> a[i];
  int ret = 0;
  for (int i = 0; i < n; i++) {
    int curr = 0;
    int maxi = 0;
    for (int j = i; j < n; j++) {
      curr ^= a[j];
      maxi = max(maxi, curr);
    }
    ret = max(ret, maxi);
  }
  cout << ret << endl;
  return 0;
}
