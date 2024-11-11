#include <bits/stdc++.h>
using namespace std;
map<vector<pair<int, int>>, int> mp;
vector<pair<int, int>> v;
const long long mod = 998244353;
const long long mod1 = 1e9 + 7;
long long power(long long a, long long b) {
  long long res = 1;
  while (b > 0) {
    if (b % 2 == 1) {
      res = (res * a) % mod1;
    }
    a = (a * a) % mod1;
    b >>= 1;
  }
  return res;
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cin.tie(nullptr);
  srand(time(NULL));
  long long factorial[1000051];
  long long fact = 1;
  factorial[0] = 1;
  for (int i = 1; i <= 1000050; i++) {
    fact = (fact * i) % mod1;
    factorial[i] = fact;
  }
  int t;
  cin >> t;
  while (t--) {
    int x, y;
    cin >> x >> y;
    vector<int> cnt;
    for (int i = 2; i <= sqrt(x); i++) {
      int count = 0;
      while (x % i == 0) {
        x /= i;
        count++;
      }
      if (count > 0) {
        cnt.push_back(count);
      }
    }
    if (x != 1) {
      cnt.push_back(1);
    }
    long long ans = 1, num = 0, den = 0;
    for (int i = 0; i < cnt.size(); i++) {
      num = factorial[y + cnt[i] - 1];
      den = power(factorial[cnt[i]], mod1 - 2);
      den = den * power(factorial[y - 1], mod1 - 2);
      den %= mod1;
      num = (num * den) % mod1;
      ans = (ans * num) % mod1;
    }
    long long two = power(2, y - 1);
    ans = (ans * two) % mod1;
    cout << ans << "\n";
  }
}
