#include <bits/stdc++.h>
using namespace std;
int main() {
  int n, d;
  cin >> n >> d;
  int totime = (n - 1) * 10;
  int churu = totime / 5;
  int sum = 0;
  int a[n];
  for (int i = 0; i < n; i++) {
    cin >> a[i];
    sum += a[i];
  }
  int ans = d - (totime + sum);
  if ((n - 1) * 10 + sum > d)
    cout << -1;
  else {
    cout << churu + (ans / 5);
  }
}
