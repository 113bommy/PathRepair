#include <bits/stdc++.h>
using namespace std;
int main() {
  int n, m;
  cin >> n >> m;
  int a[100000];
  int lastdeal = 1;
  long long res = 0;
  for (int i = 0; i < m; i++) {
    cin >> a[i];
    if (a[i] >= lastdeal) {
      res += a[i] - lastdeal;
      lastdeal = a[i];
    } else {
      res += (n - lastdeal) + a[i];
      lastdeal = a[i];
    }
  }
  cout << res;
  return 0;
}
