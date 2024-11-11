#include <bits/stdc++.h>
using namespace std;
long long n, a[100005][2];
int main(int argc, char const *argv[]) {
  cin >> n;
  if (n % 2 != 0) {
    cout << "NO" << endl;
    return 0;
  }
  for (int i = 0; i < n; i++) cin >> a[i][0] >> a[i][1];
  long long x, y;
  x = a[0][0] + a[n / 2][0];
  y = a[0][1] + a[n / 2][1];
  for (int i = 1; i < n / 2; i++) {
    if (a[i][0] + a[n / 2 + i][0] != x && a[i][1] + a[n / 2 + i][1] != y) {
      cout << "NO" << endl;
      return 0;
    }
  }
  cout << "YES" << endl;
  return 0;
}
