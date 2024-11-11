#include <bits/stdc++.h>
using namespace std;
const int MOD = 1e9 + 7;
const long long INF = 1e18;
const int OFF = (1 << 20);
int n;
int a[100002];
int main() {
  cin >> n;
  for (int i = 0; i < n; i++) cin >> a[i];
  cout << "1 1\n" << -a[0] << "\n";
  a[0] = 0;
  if (n == 1)
    cout << "1 1\n 0\n";
  else {
    cout << "2 " << n << "\n";
    for (int i = 1; i < n; i++) {
      long long tren = n - 1;
      tren *= a[i];
      a[i] += tren;
      cout << tren << " ";
    }
    cout << "\n";
  }
  cout << "1 " << n << "\n";
  for (int i = 0; i < n; i++) {
    cout << -a[i] << " ";
  }
  return 0;
}
