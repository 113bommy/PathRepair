#include <bits/stdc++.h>
using namespace std;
template <class T>
void debug(T a, T b) {
  ;
}
template <class T>
void chmin(T& a, const T& b) {
  if (a > b) a = b;
}
template <class T>
void chmax(T& a, const T& b) {
  if (a < b) a = b;
}
namespace std {
template <class S, class T>
ostream& operator<<(ostream& out, const pair<S, T>& a) {
  out << '(' << a.first << ',' << a.second << ')';
  return out;
}
}  // namespace std
unsigned long long int readL() {
  unsigned long long int res;
  scanf("%I64d", &res);
  return res;
}
void printL(unsigned long long int res) { printf("%I64d", res); }
int m;
int n;
bitset<2005> basis[2005];
bitset<2005> eff[2005];
int h[2005];
bitset<2005> getit() {
  string s;
  cin >> s;
  reverse((s).begin(), (s).end());
  bitset<2005> res;
  res.reset();
  vector<unsigned long long int> X, Y;
  for (int i = 0; i < s.size(); i += 9) {
    unsigned long long int cur = 0;
    for (int j = 8; j >= 0; --j)
      cur = cur * 10 + (i + j < s.size() ? s[i + j] - '0' : 0);
    X.push_back(cur);
  }
  int pos = 0;
  unsigned long long int e9 = 1000000000, mod = (1 << 30);
  while (!X.empty()) {
    Y.clear();
    unsigned long long int cur = 0;
    for (int i = X.size() - 1; i >= 0; --i) {
      cur = cur * e9 + X[i];
      Y.push_back(cur / mod);
      cur %= mod;
    }
    for (int i = 0; i < (30); ++i)
      if (cur >> i & 1) {
        res.set(i + pos);
      }
    pos += 30;
    reverse((Y).begin(), (Y).end());
    while (!Y.empty() && Y.back() == 0) Y.pop_back();
    X = Y;
  }
  return res;
}
int main() {
  cin >> m;
  for (int t = 0; t < (m); ++t) {
    bitset<2005> cur = getit();
    eff[n].reset();
    eff[n].set(t);
    for (int i = 0; i < (n); ++i)
      if (cur.test(h[i])) {
        cur ^= basis[i];
        eff[n] ^= eff[i];
      }
    if (cur.any()) {
      basis[n] = cur;
      for (int i = 0; i < (2000); ++i)
        if (cur.test(i)) {
          h[n] = i;
          break;
        }
      ++n;
      puts("0");
    } else {
      vector<int> res;
      for (int i = 0; i < (t); ++i)
        if (eff[n].test(i)) {
          res.push_back(i);
        }
      printf("%d", (int)res.size());
      for (int i = 0; i < (res.size()); ++i) printf(" %d", res[i]);
      putchar('\n');
    }
  }
  return 0;
}
