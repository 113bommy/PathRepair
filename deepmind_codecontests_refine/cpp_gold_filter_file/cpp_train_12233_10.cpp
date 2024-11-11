#include <bits/stdc++.h>
using namespace std;
int main() {
  long long n;
  cin >> n;
  set<long long> f;
  long long i = 2;
  while (i * i <= n) {
    if (n % i == 0)
      f.insert(i), n /= i;
    else
      i++;
  }
  f.insert(n);
  long long ans = 1;
  for (auto it = f.begin(); it != f.end(); it++) {
    ans *= (*it);
  }
  cout << ans << "\n";
}
