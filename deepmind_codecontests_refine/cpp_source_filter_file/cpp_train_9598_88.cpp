#include <bits/stdc++.h>
using namespace std;
int main() {
  long long n, a, b;
  cin >> n >> a >> b;
  long long maxa = max(a + 1, n - b - 1);
  long long ans = n - maxa + 1;
  cout << ans;
  return 0;
}
