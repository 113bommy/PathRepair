#include <bits/stdc++.h>
using namespace std;
long long const mod = 1000000007;
long long const md = 998244353;
long long mypowr(long long a, long long b) {
  long long res = 1;
  if (b < 0) b = 0;
  a %= mod;
  assert(b >= 0);
  for (; b; b >>= 1) {
    if (b & 1) res = res * a % mod;
    a = a * a % mod;
  }
  return res;
}
long long mypow(long long a, long long b) {
  long long res = 1;
  if (b < 0) b = 0;
  assert(b >= 0);
  for (; b; b >>= 1) {
    if (b & 1) res = res * a;
    a = a * a;
  }
  return res;
}
ifstream in("input.txt");
ofstream out("output.txt");
unordered_map<char, long long> q;
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  cout << fixed << setprecision(15);
  string s;
  cin >> s;
  int n = s.size();
  for (int i = 0; i < n; ++i) {
    ++q[s[i]];
  }
  long long cnt = 0;
  for (int i = int('a'); i <= int('z'); ++i) {
    char c = char(i);
    cnt += q[c] * q[c];
  }
  for (int i = int('0'); i <= int('9'); ++i) {
    char c = char(i);
    cnt += q[c] * q[c];
  }
  cout << cnt << '\n';
  return 0;
}
