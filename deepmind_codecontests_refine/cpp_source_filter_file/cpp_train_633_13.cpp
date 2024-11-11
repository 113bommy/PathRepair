#include <bits/stdc++.h>
using namespace std;
int main() {
  long long int n;
  cin >> n;
  long long int ans = 0, a, b, c, d;
  long long int root = pow(n, 0.5) + 1;
  for (int i = 2; i < (n / 2); i++) {
    a = n / i;
    a = (a * (a + 1)) / 2;
    a--;
    ans += a;
  }
  cout << ans * 4;
}
