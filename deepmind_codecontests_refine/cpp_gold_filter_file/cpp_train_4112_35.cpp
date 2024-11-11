#include <bits/stdc++.h>
using namespace std;
int a[200][200];
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  long long n;
  cin >> n;
  long long sol = 0;
  for (long long p = 1, i = 1; p <= n; p *= 10, ++i) {
    if (p * 10 <= n)
      sol += (p * 10 - p) * i;
    else
      sol += (n - p + 1) * i;
  }
  cout << sol;
  return 0;
}
