#include <bits/stdc++.h>
using namespace std;
const int maxn = 1e6 + 5;
string a, b;
long long n, m, la, lb, ans = 0;
int Count_char[maxn][30];
long long GCD(long long x, long long y) {
  while (y) {
    long long z = x % y;
    x = y;
    y = z;
  }
  return x;
}
long long LCM(long long x, long long y) { return x / GCD(x, y) * y; }
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cin >> n >> m;
  cin >> a >> b;
  la = a.length();
  lb = b.length();
  long long gcd = GCD(la, lb);
  long long lcm = LCM(la, lb);
  for (int i = 0; i < la; i++) Count_char[i % gcd + 1][a[i] - 'a']++;
  ans = lcm;
  for (int i = 0; i < lb; i++) ans -= Count_char[i % gcd + 1][b[i] - 'a'];
  cout << ans * la / lcm * n;
}
