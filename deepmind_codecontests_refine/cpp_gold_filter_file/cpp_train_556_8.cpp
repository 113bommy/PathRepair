#include <bits/stdc++.h>
using namespace std;
long long int num = pow(10, 9) + 7;
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  int t = 9;
  int a[9];
  for (int i = 0; i < 9; ++i) {
    cin >> a[i];
  }
  a[4] = (a[3] + a[1] + a[5] + a[7] - a[2] - a[6]) / 2;
  a[0] = a[4] - (a[1] - a[6]);
  a[8] = a[1] + a[2] - a[4];
  for (int i = 0; i < 9; ++i) {
    if (i % 3 == 0) cout << endl;
    cout << a[i] << " ";
  }
}
