#include <bits/stdc++.h>
using namespace std;
int main() {
  int t, n;
  long long dem;
  cin >> t;
  for (int i = 1; i <= t; i++) {
    dem = 1;
    cin >> n;
    for (int j = 1; j <= n; j++) {
      dem = (dem * j) % 1000000007;
    }
    cout << dem << endl;
  }
}
