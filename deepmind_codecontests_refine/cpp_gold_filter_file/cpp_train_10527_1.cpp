#include <bits/stdc++.h>
using namespace std;
long long n, k, ans = 1000000000;
int main() {
  cin >> n >> k;
  for (int i = 1; i < k; ++i)
    if (n % i == 0)
      if (n / i * k + i <= ans) ans = n / i * k + i;
  cout << ans;
}
