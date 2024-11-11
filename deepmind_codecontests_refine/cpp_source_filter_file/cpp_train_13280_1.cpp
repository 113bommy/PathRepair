#include <bits/stdc++.h>
using namespace std;
long long x, y, z, arr[100 * 100005], rearr[100 * 100005];
int main() {
  ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
  ;
  cin >> x >> y;
  for (int i = 0; i < x; i++) {
    cin >> z;
    arr[z]++;
  }
  z = 0;
  for (int i = 14; i >= 1; i--) {
    z += arr[i];
    arr[i / 2] += arr[i] + rearr[i];
    rearr[i / 2 + i % 2] += arr[i] + rearr[i];
    if (z >= y) {
      cout << i << endl;
      return 0;
    }
  }
  cout << -1 << endl;
  return 0;
}
