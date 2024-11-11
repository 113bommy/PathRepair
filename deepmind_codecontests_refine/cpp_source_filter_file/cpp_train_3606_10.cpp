#include <bits/stdc++.h>
using namespace std;
bool check(int x) {
  if (x <= 0) return true;
  if (sqrt(x) == (int)sqrt(x))
    return false;
  else
    return true;
}
int n, mx = INT_MIN;
int a[1005];
int main() {
  cin >> n;
  for (int i = 0; i < n; i++) {
    cin >> a[i];
    if (check(a[i]))
      if (a[i] > mx) mx = a[i];
  }
  cout << mx;
}
