#include <bits/stdc++.h>
using namespace std;
int n, c, i, a[100001], l = 1;
int main() {
  cin >> n >> c >> a[1];
  for (i = 2; i <= n; i++) {
    cin >> a[i];
    if (a[i] - a[i - 1] <= c) {
      l++;
    } else {
      l = 1;
    }
  }
  cout << l;
}
