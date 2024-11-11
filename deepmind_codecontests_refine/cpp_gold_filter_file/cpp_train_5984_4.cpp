#include <bits/stdc++.h>
using namespace std;
long long const mod = 1000000007;
long long powmod(long long a, long long b) {
  long long res = 1;
  a %= mod;
  assert(b >= 0);
  for (; b; b >>= 1) {
    if (b & 1) res = res * a % mod;
    a = a * a % mod;
  }
  return res;
}
ifstream in("txt.in");
ofstream out("txt.out");
int main() {
  cout << fixed << setprecision(12);
  cin.tie(0);
  ios_base::sync_with_stdio(0);
  cout.tie(0);
  string s;
  cin >> s;
  int n = s.size();
  sort(s.begin(), s.end());
  long long sum = 1;
  long long cnt = s.size();
  for (int i = 1; i < n; ++i) {
    if (s[i] == s[i - 1])
      ++sum;
    else {
      cnt += sum * (sum - 1);
      sum = 1;
    }
  }
  cout << cnt + sum * (sum - 1) << '\n';
  return 0;
}
