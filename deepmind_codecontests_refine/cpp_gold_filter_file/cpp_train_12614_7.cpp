#include <bits/stdc++.h>
using namespace std;
const int64_t inf = 2e9;
int64_t inp() {
  int64_t x;
  cin >> x;
  return x;
}
string inp_str() {
  string x;
  cin >> x;
  return x;
}
int64_t sqr(int64_t n) { return n * n; }
int64_t power(int64_t a, int64_t b, int64_t mod = inf) {
  int64_t res = 1;
  a %= mod;
  for (int64_t i = (0); i <= (log2(b)); ++i) {
    if (b & (1 << i)) res = (res * a) % mod;
    a = (a * a) % mod;
  }
  return res;
}
int64_t gcd(int64_t a, int64_t b) {
  while (b > 0) {
    int64_t tmp = a % b;
    a = b;
    b = tmp;
  }
  return a;
}
bool is_pal(string s) { return equal(begin(s), end(s), s.rbegin()); }
void fast_io() {
  ios::sync_with_stdio(0);
  cin.tie(0);
}
void print_bool(bool a) {
  if (a)
    cout << "YES\n";
  else
    cout << "NO\n";
}
int64_t n;
vector<int64_t> a;
void Input() {
  cin >> n;
  a.clear();
  a.resize(n + 1);
  generate(1 + begin(a), end(a), inp);
}
void Solve() {
  int64_t sum = -n * (n - 1) / 2;
  unordered_map<int64_t, int64_t> cnt;
  for (int64_t i = (1); i <= (n); ++i) sum += a[i], cnt[a[i]]++;
  bool firstMoveLose = cnt[0] > 1;
  int64_t appeared = -1;
  for (int64_t i = (1); i <= (n); ++i) {
    firstMoveLose |= (cnt[a[i]] > 1 && cnt[a[i] - 1] > 0) || (cnt[a[i]] > 2);
    if (cnt[a[i]] > 1) {
      if (appeared > -1 && appeared != a[i])
        firstMoveLose = true;
      else if (appeared == -1)
        appeared = a[i];
    }
  }
  if (firstMoveLose || sum % 2 == 0)
    cout << "cslnb";
  else
    cout << "sjfnb";
}
int main() {
  fast_io();
  Input(), Solve();
  return 0;
}
