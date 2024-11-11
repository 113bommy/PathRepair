#include <bits/stdc++.h>
using namespace std;
int main() {
  long long int n, a, b, ans;
  cin >> n >> a >> b;
  ans = (a + b + n) % n;
  if (ans != 0)
    cout << ans << "\n";
  else
    cout << n << "\n";
}
