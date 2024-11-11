#include <bits/stdc++.h>
using namespace std;
const long long int INF = (1LL << 60) - 1;
const long long int MAX = 2000000000000;
long long int fast_exp(long long int base, long long int exp, long long int m) {
  long long int res = 1;
  while (exp > 0) {
    if (exp % 2 == 1) {
      res = (res * base) % m;
    }
    base = (base * base) % m;
    exp /= 2;
  }
  return res % m;
}
int main() {
  ios ::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  long long int k, sum = 0, ans = 0;
  cin >> k;
  string s;
  cin >> s;
  int l = s.length();
  std::vector<int> v;
  for (int i = 0; i < l; i++) {
    sum += (s[i] - '0');
    v.push_back(s[i] - '0');
  }
  if (sum >= k) {
    cout << 0 << endl;
    return 0;
  }
  sum = k - sum;
  sort(v.begin(), v.end());
  for (int i = 0; i < l; i++) {
    if (sum <= (9 - v[i])) {
      ans++;
      break;
    }
    sum -= (9 - v[i]);
    ans++;
  }
  cout << ans << endl;
  return 0;
}
