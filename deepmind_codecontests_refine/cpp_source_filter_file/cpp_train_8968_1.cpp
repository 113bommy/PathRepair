#include <bits/stdc++.h>
using namespace std;
struct prll {
  template <typename T>
  prll& operator,(const T& v) {
    (v == '\n') ? (cerr << '\n') : (cerr << v << ", ");
    return *this;
  }
} pr;
long long power(long long b, long long p) {
  long long res = 1, x = b;
  while (p > 0) {
    if (p & 1ll) res = res * x;
    x = x * x;
    p >>= 1;
  }
  return res;
}
long long bigmod(long long b, long long p, long long m) {
  long long res = 1, x = b % m;
  while (p > 0) {
    if (p & 1) res = (res * x) % m;
    x = (x * x) % m;
    p >>= 1;
  }
  return res;
}
const int mod = 998244353;
pair<int, int> arr[203];
void solve() {
  string str;
  cin >> str;
  vector<int> v;
  for (int i = 0, j, lst = 0; i < str.size(); ++i) {
    j = i;
    while (j < str.size() && str[j] == 'v') {
      ++j;
    }
    if (str[i] == 'v') {
      lst += j - i - 1;
      if (j == str.size()) v.push_back(lst);
      i = j - 1;
    } else
      v.push_back(lst);
  }
  long long ans = 0;
  for (int i = 0; i + 1 < v.size(); ++i) {
    ans += v[i] * (v.back() - v[i]);
  }
  cout << ans << endl;
}
int main() {
  { solve(); }
}
