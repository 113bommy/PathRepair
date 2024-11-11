#include <bits/stdc++.h>
using namespace std;
int main() {
  ios_base::sync_with_stdio(false);
  long long k, n, s, p;
  cin >> k >> n >> s >> p;
  long long eachPerson = (n / s) + (n % k != 0);
  long long totalSheets = eachPerson * k;
  long long ans = (totalSheets / p) + (totalSheets % p != 0);
  cout << ans << "\n";
  return 0;
}
