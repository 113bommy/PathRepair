#include <bits/stdc++.h>
using namespace std;
long long gcd_ll(long long a, long long b) { return a ? gcd_ll(b % a, a) : b; }
long long lcm_ll(long long a, long long b) { return (a / gcd_ll(a, b)) * b; }
int gcd(int a, int b) { return a ? gcd(b % a, a) : b; }
int lcm(int a, int b) { return (a / gcd(a, b)) * b; }
string int_to_str_easy(long long n) {
  return n ? "" : int_to_str_easy(n / 10) + (char)('0' + n % 10);
}
long long sum(vector<long long> v) {
  long long ans = 0;
  for (long long i : v) ans += i;
  return ans;
}
bool is_down(char x) { return ('a' <= x && x <= 'z'); }
bool is_upper(char x) { return ('A' <= x && x <= 'Z'); }
bool is_digit(char x) { return ('0' <= x && x <= '9'); }
string follow(string s) {
  for (int i = 0; i < s.length(); i++)
    if (is_upper(s[i])) s[i] += 'a' - 'A';
  return s;
}
const long double pi = 3.141592653589793238462643383279;
const long double log23 = 1.58496250072115618145373894394781;
const long double eps = 1e-8;
const long double zero = 0;
const long long INF = 1e18;
const int COUT = 30;
const int prost = 239;
const long long prost64 = 239;
const long long MOD = 1000000007;
const int BIG = 1e9;
const int alf = 26;
const int MAX_N = 1e5 + 1;
const int MAX_M = 501;
const int km = (1 << 18) - 1;
const int dxo[8] = {-1, -1, -1, 0, 1, 1, 1, 0};
const int dyo[8] = {-1, 0, 1, 1, 1, 0, -1, -1};
const int dx[4] = {-1, 0, 1, 0};
const int dy[4] = {0, 1, 0, -1};
void solve() { return; }
int main() {
  cin.sync_with_stdio(0);
  string s;
  cin >> s;
  bool xa = true;
  for (char x : s) xa &= (x == 'a');
  if (xa) {
    for (int i = 0; i < s.length() - 1; i++) cout << 'a';
    cout << 'z';
    return 0;
  }
  int pos = 0;
  for (int i = 0; i < s.length(); i++)
    if (s[i] != 'a') {
      pos = i;
      break;
    }
  int en = s.length();
  for (int i = pos; i < s.length(); i++)
    if (s[i] == 'a') {
      en = i;
      break;
    }
  for (int i = 0; i < pos; i++) cout << s[i];
  for (int i = pos; i < en; i++) cout << (char)(s[i] - 1);
  for (int i = en; i < s.length(); i++) cout << s[i];
  return 0;
}
