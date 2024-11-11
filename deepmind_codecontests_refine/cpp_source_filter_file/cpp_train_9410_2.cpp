#include <bits/stdc++.h>
using namespace std;
const int mod = 1000000007;
const long long inf = 1e18 + 5;
const long long MX = 303030;
int cox[4] = {1, -1, 0, 0};
int coy[4] = {0, 0, 1, -1};
int dx[] = {-1, 0, 1, 0, -1, +1, +1, -1};
int dy[] = {0, 1, 0, -1, +1, +1, -1, -1};
long long gcd(long long a, long long b) { return b ? gcd(b, a % b) : a; }
long long lcm(long long a, long long b) { return a * b / gcd(a, b); }
long long C(int a, int b) {
  if (b > a - b) b = a - b;
  long long res = 1;
  for (int i = 0; i < b; i++) res = res * (a - i) / (i + 1);
  return res;
}
long long unsigned power(long long N, long long R) {
  if (R == 0) return 1;
  long long unsigned p = (power(N, R / 2)) % mod;
  p = (p * p) % mod;
  if (R % 2) p = (p * N) % mod;
  return p;
}
bool prime(long long n) {
  if (n < 2) return false;
  for (int i = 2; i * i <= n; i++)
    if (!(n % i)) return false;
  return true;
}
int main() {
  ios_base::sync_with_stdio(false), cin.tie(0), cout.tie(0);
  string s;
  cin >> s;
  int a{}, b{};
  for (int i = 0, sz = (int)s.size(); i < sz; i++)
    if (s[i] == '@') a++;
  if (s[0] == '@' || s[s.size() - 1] == '@')
    cout << "No solution\n";
  else {
    string ans;
    int f{}, ch{}, c{};
    for (int i = 0, sz = (int)s.size(); i < sz; i++) {
      if ((s[i] != '@' && !ch) || (s[i] != '@' && ch && !a))
        ans.push_back(s[i]), c = 1;
      else if (s[i] != '@' && ch && a > 0)
        ans.push_back(s[i]), ans.push_back(','), ch = 0;
      else if (s[i] == '@' && c) {
        a--;
        ch = 1;
        if (s[i] == ans.back()) {
          f = 1;
          break;
        }
        ans.push_back(s[i]);
        c = 0;
      } else if (s[i] == '@' && !c) {
        f = 1;
        break;
      }
    }
    (f) ? cout << "No solution\n" : cout << ans << '\n';
  }
  return 0;
}
