#include <bits/stdc++.h>
using namespace std;
long long int x, y, z, res, arr[(int)2e5 + 9];
int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  cin >> x;
  for (int i = 0; i < x; i++) cin >> arr[i];
  cin >> y >> z;
  for (int i = 0; i < x; i++) {
    res += floor((double)(arr[i] - y) / (double)(y + z));
  }
  cout << res * z;
  return 0;
}
