#include <bits/stdc++.h>
const int MOD = 1000000007;
const int MAX = 10000005;
using namespace std;
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  long long n, m;
  cin >> n >> m;
  long long l, r;
  for (long long i = 0; i < m; i++) {
    cin >> l >> r;
  }
  while (n--) {
    cout << n % 2;
  }
}
