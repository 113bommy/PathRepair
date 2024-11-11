#include <bits/stdc++.h>
using namespace std;
vector<int> primes;
using ll = long long int;
using dl = double;
ll aarray[100000 + 10];
char magic[1][100000];
const int N = 2e5 + 10;
int main() {
  ios_base::sync_with_stdio(false);
  ll n, a, b, ans = INT_MIN, i, j, k;
  cin >> n >> k;
  for (i = 1; i <= n; i++) {
    cin >> aarray[i];
  }
  aarray[n + 1] = aarray[n];
  a = aarray[1];
  ll cnt = 0;
  cnt++;
  for (i = 2; i <= n + 1; i++) {
    if (aarray[i] != a) {
      cnt++;
      a = aarray[i];
    } else {
      ans = max(ans, cnt);
      cnt = 0;
      cnt += 1;
      a = aarray[i];
    }
  }
  if (ans == INT_MIN)
    cout << 1 << endl;
  else
    cout << ans << endl;
}
