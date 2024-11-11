#include <bits/stdc++.h>
using namespace std;
long long int mod = 1e9 + 7;
long long int ceil1(long long int n, long long int k) {
  if (n % k) return n / k + 1;
  return n / k;
}
long long int pow1(long long int n, long long int k, long long int modu) {
  long long int ans = 1;
  while (k != 0) {
    if (k % 2) ans = (ans * n) % modu;
    n = (n * n) % modu;
    k = k / 2;
  }
  return ans % modu;
}
bool ispal(string s) {
  long long int i = 0;
  long long int j = s.size() - 1;
  while (i < j) {
    if (s[i] != s[j]) return false;
    i++;
    j--;
  }
  return true;
}
long long int gcdd(long long int a, long long int b) {
  if (b == 0) return a;
  return gcdd(b, a % b);
}
long long int fact(long long int n) {
  if (n == 1 || n == 0)
    return 1;
  else
    return (n * fact(n - 1));
}
bool isprime(long long int n) {
  if (n <= 1) return false;
  if (n <= 3) return true;
  if (n % 2 == 0 || n % 3 == 0) return false;
  for (long long int i = 5; i * i <= n; i = i + 6)
    if (n % i == 0 || n % (i + 2) == 0) return false;
  return true;
}
void solve() {
  string s, t;
  cin >> s >> t;
  string ans;
  cin >> ans;
  map<long long int, long long int> ms;
  for (long long int i = 0; i < s.size(); i++) {
    ms[s[i] - 'a'] = i;
  }
  for (long long int i = 0; i < ans.size(); i++) {
    if (ans[i] >= 'A' && ans[i] <= 'Z') {
      cout << char(t[ms[ans[i] - 'A']] - 32);
    } else if (ans[i] >= 'a' && ans[i] <= 'z') {
      cout << t[ms[ans[i] - 'a']];
    } else
      cout << ans[i];
  }
  return;
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  long long int q = 1;
  while (q--) {
    solve();
  }
  return 0;
}
