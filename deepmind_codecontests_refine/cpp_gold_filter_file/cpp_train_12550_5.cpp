#include <bits/stdc++.h>
using namespace std;
int main() {
  int n, c, d = 1;
  cin >> n >> c;
  int a[n];
  for (int t = 0; t < n; t++) {
    cin >> a[t];
  }
  for (int t = 0; t < n - 1; t++) {
    if (a[t + 1] - a[t] <= c)
      d++;
    else
      d = 1;
  }
  cout << d;
}
