#include <bits/stdc++.h>
using namespace std;
void cout_vector(vector<int> v) {
  for (long long unsigned i = 0; i < v.size(); i++) cout << v[i] << " ";
  cout << endl;
}
void cout_vector(vector<long long> v) {
  for (long long unsigned i = 0; i < v.size(); i++) cout << v[i] << " ";
  cout << endl;
}
int sum_vector(vector<int> v) { return accumulate(v.begin(), v.end(), 0); }
void sort_vector(vector<int> &v) { sort(v.begin(), v.end()); }
void sort_comp(vector<int> &v, bool func(int, int)) {
  sort(v.begin(), v.end(), func);
}
bool comp(int a, int b) {
  bool aend = 0;
  if (a % 2) a--, aend = 1;
  if (b % 2) b--;
  a /= 2;
  b /= 2;
  if (a == b) {
    if (aend) return 1;
    return 0;
  }
  if (a < b) return 1;
  return 0;
}
long long gcd(long long a, long long b) {
  while (a) {
    long long temp = a;
    a = b % a;
    b = temp;
  }
  return abs(b);
}
long long lcm(long long a, long long b) { return (a * b) / gcd(a, b); }
string binary(long long num) {
  string ans = "";
  do {
    ans = to_string(num % 2) + ans;
    num /= 2;
  } while (num);
  return ans;
}
const int mxn = 1e5 + 2;
const long long mod = 1e9 + 7;
long long pwr(long long num, long long p) {
  long long res = 1;
  while (p > 0) {
    if (p & 1) res = (res * num) % mod;
    num = (num * num) % mod;
    p /= 2;
  }
  return res;
}
long long inverse(long long num) { return pwr(num, mod - 2); }
void solve() {
  string s;
  cin >> s;
  int n = s.size();
  int cl = 0;
  char prev = '2';
  for (int i = 0; i < n; i++) {
    char ch = s[i];
    cl++;
    if (ch == 'a' || ch == 'e' || ch == 'i' || ch == 'o' || ch == 'u')
      cl = 0;
    else {
      if (i > 1 && s[i] == s[i - 1] && s[i - 1] == s[i - 2]) {
        cl = 2;
      }
    }
    if (cl >= 3) {
      cout << " ";
      cl = 1;
    }
    cout << ch;
  }
}
int main() {
  ios_base::sync_with_stdio(false), cin.tie(NULL);
  int t;
  t = 1;
  while (t--) solve();
  return 0;
}
