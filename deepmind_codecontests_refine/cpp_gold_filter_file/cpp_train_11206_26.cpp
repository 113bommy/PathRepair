#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ld = long double;
const int inf = 0x3c3c3c3c;
const long long infl = 0x3c3c3c3c3c3c3c3c;
int main() {
  cin.tie(NULL);
  cin.sync_with_stdio(false);
  cout.sync_with_stdio(false);
  ll n, k;
  cin >> n >> k;
  if (k == 1) {
    return !printf("Yes");
  }
  for (ll i = 1; i <= k; i++) {
    if (n % i != i - 1) {
      return !printf("No");
    }
  }
  printf("Yes");
}
