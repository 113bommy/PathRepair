#include <bits/stdc++.h>
using namespace std;
long long n, i, x, ans, ns, a[2000000];
int main() {
  cin >> n;
  for (i = 1; i <= n; i++) {
    cin >> x;
    a[x] = i;
  }
  ans = n;
  ns = x;
  for (i = 1; i <= 1000000; i++)
    if (a[i])
      if (a[i] < ans) {
        ans = a[i];
        ns = i;
      }
  cout << ns;
}
