#include <bits/stdc++.h>
using namespace std;
int n, a[100000], ans;
int main() {
  cin >> n;
  for (int i = 1; i <= n; i++) {
    int x;
    cin >> x;
    a[x]++;
  }
  for (int i = 1; i <= 10000; i++) {
    if (a[i]) {
      ans += (a[i] / 2);
    }
  }
  cout << ans / 2;
  return 0;
}
