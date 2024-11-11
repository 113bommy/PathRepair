#include <bits/stdc++.h>
using namespace std;
const int oo = 1e9 + 5;
const int N = 1e5 + 5;
int ans = 0;
int main() {
  int n;
  cin >> n;
  int a[n], mx = -N;
  for (int(i) = (0); (i) < (n); i++) {
    cin >> a[i];
    if (a[i] > mx) mx = a[i];
    ans += a[i];
  }
  ans = (ans + 1) * 2;
  if (ans % n)
    ans = (ans / n) + 1;
  else
    ans = (ans / n);
  cout << max(ans, mx) << endl;
  return 0;
}
