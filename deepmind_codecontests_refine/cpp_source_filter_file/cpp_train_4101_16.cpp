#include <bits/stdc++.h>
using namespace std;
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  int n, k;
  cin >> n >> k;
  vector<long long> v;
  for (int i = 1; i <= n; i++) {
    string s;
    cin >> s;
    int e = 24;
    long long val = 0, val1 = 0;
    for (int i = 0; i < s.size(); i++) {
      if (s[i] == '.') {
        val |= (val1) << e;
        e -= 8;
        val1 = 0;
      } else {
        val1 *= 10;
        val1 += (s[i] - '0');
      }
    }
    val |= val1;
    v.push_back(val);
  }
  long long t = 0;
  for (int i = 31; i >= 0; i--) {
    t |= (1ll << i);
    set<long long> s;
    for (int i = 0; i < n; i++) {
      long long x = v[i] & t;
      s.insert(x);
    }
    if (s.size() == k) {
      long long a = (t >> 24ll) & 255ll;
      long long b = (t >> 16ll) & 255ll;
      long long c = (t >> 8ll) & 255ll;
      long long d = t & 255ll;
      cout << a << "." << b << "." << c << "." << d;
      return 0;
    }
  }
  cout << -1;
}
