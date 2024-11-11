#include <bits/stdc++.h>
using namespace std;
long long gcd(long long a, long long b) { return (b == 0) ? a : gcd(b, a % b); }
long long lcm(long long a, long long b) { return (a * b) / gcd(a, b); }
long long powmod(long long a, long long b) {
  long long res = 1;
  if (a >= 1000000007) a %= 1000000007;
  for (; b; b >>= 1) {
    if (b & 1) res = res * a;
    if (res >= 1000000007) res %= 1000000007;
    a = a * a;
    if (a >= 1000000007) a %= 1000000007;
  }
  return res;
}
void fast() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
}
void fileIO() {
  freopen("input.in", "r", stdin);
  freopen("output1.txt", "w", stdout);
}
map<long long, int> m[26];
string s;
int x;
const int N = 1e5 + 5;
long long ans, sum, cost[N];
int main() {
  for (int i = 0; i < 26; i++) {
    cin >> x;
    cost[i] = x;
  }
  cin >> s;
  for (int i = 0; i < s.length(); i++) {
    ans += m[s[i] - 'a'][sum];
    sum += cost[s[i] - 'a'];
    m[s[i] - 'a'][sum]++;
  }
  cout << ans;
  return 0;
}
