#include <bits/stdc++.h>
using namespace std;
int main() {
  int n, n1[100], k, mx;
  double cnt = 0.0;
  cin >> n >> k;
  for (int i = 0; i < n; i++) {
    cin >> n1[i];
    cnt += n1[i];
  }
  mx = cnt;
  for (int j = 0; j <= 10000; j++) {
    mx = cnt;
    {
      mx = round((cnt + (k * j)) / (j + n));
      mx = round(mx);
      if (mx == k) {
        cout << j << endl;
        break;
      }
    }
  }
}
