#include <bits/stdc++.h>
using namespace std;
const long long INF = (long long)1000 * 1000 * 1000 * 1000 * 1000 * 100;
const int MOD = 1000000007;
string intToStr(int a) {
  string res;
  for (; a; a /= 10) {
    res += a % 10 + '0';
  }
  if (res.empty()) res += '0';
  reverse(res.begin(), res.end());
  return res;
}
string iptoStr(unsigned int ip) {
  string res;
  unsigned int st = (1 << 24);
  while (st) {
    res += intToStr(ip / st);
    ip %= st;
    st >>= 8;
    if (st) res += '.';
  }
  return res;
}
bool isDig(char ch) { return (ch >= '0' && ch <= '9'); }
int main() {
  std::ios_base::sync_with_stdio(false);
  int n, k;
  cin >> n >> k;
  vector<unsigned int> ip(n);
  for (int i = 0; i < n; ++i) {
    unsigned int cur = 0;
    for (int j = 0; j < 4; ++j) {
      unsigned int tmp = 0;
      char ch;
      while (isDig(ch = getchar())) {
        tmp = tmp * 10 + ch - '0';
      }
      cin >> tmp;
      cur = (cur << 8) + tmp;
    }
    ip[i] = cur;
  }
  set<unsigned int> s;
  unsigned int mask = 0;
  for (int st = 31; st; --st) {
    mask |= (1 << st);
    s.clear();
    for (int i = 0; i < n; ++i) {
      s.insert(mask & ip[i]);
    }
    if (s.size() == k) {
      cout << iptoStr(mask) << endl;
      return 0;
    }
    if (s.size() > k) {
      break;
    }
  }
  cout << -1 << endl;
  return 0;
}
