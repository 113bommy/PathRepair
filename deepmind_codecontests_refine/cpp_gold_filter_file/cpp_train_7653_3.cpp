#include <bits/stdc++.h>
using namespace std;
int main() {
  int n;
  cin >> n;
  int a[1000];
  int k;
  cin >> k;
  a[n] = k;
  for (__typeof(n) i = 0; i < (n); i++) {
    cin >> a[i];
  }
  int cnt = 0;
  while (a[0] < k) {
    cnt++;
    for (__typeof(n) i = 0; i < (n); i++) {
      if (a[i] != a[i + 1]) a[i]++;
    }
  }
  cout << cnt;
  return 0;
}
