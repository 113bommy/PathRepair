#include <bits/stdc++.h>
using namespace std;
int main() {
  int n, k, t, cnt = 0;
  cin >> n;
  int a[n * 2];
  for (int i = 0; i < n * 2; i++) {
    cin >> a[i];
  }
  cin >> k;
  for (int i = 0; i < n - 1; i += 2) {
    int l, r;
    l = a[i];
    r = a[i + 1];
    if (k > r) {
      cnt++;
    }
  }
  t = n - cnt;
  cout << t;
  return 0;
}
