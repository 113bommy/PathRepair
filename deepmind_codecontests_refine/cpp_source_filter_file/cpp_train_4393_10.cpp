#include <bits/stdc++.h>
using namespace std;
const long double eps = 1e-9;
int s2i(string s) {
  istringstream is(s);
  int a;
  is >> a;
  return a;
}
string i2s(int a) {
  ostringstream os;
  os << a;
  return os.str();
}
const long long p = 10;
const int maxn = 200000;
long long powp[maxn];
map<long long, int> was;
long long get_hash(const string &s) {
  long long hash = 0;
  for (int i = 0; i < s.length(); ++i) hash = hash * p + s[i] - '0';
  return hash;
}
int main() {
  powp[0] = 1;
  for (int i = 1; i < maxn; ++i) powp[i] = powp[i - 1] * p;
  int n;
  int k;
  cin >> n >> k;
  string s;
  cin >> s;
  int it = 0;
  string t = s;
  long long hash = get_hash(s);
  int last = 0;
  while (was.count(hash) == 0 && it < k) {
    was[hash] = it;
    for (int i = last; i + 1 < s.length(); ++i)
      if (s[i] == '4' && s[i + 1] == '7') {
        if (i % 2 == 0) {
          s[i] = s[i + 1] = '4';
          hash -= powp[s.length() - (i + 1) - 1] * 7;
          hash += powp[s.length() - (i + 1) - 1] * 4;
          last = i + 1;
        } else {
          s[i] = s[i + 1] = '7';
          hash -= powp[s.length() - (i)-1] * 4;
          hash += powp[s.length() - (i)-1] * 7;
          last = i - 1;
          if (last < 0) last = 0;
        }
        break;
      }
    ++it;
  }
  if (it == k)
    cout << s << endl;
  else {
    int cyc = it - was[hash];
    int rem = k - was[hash];
    rem %= cyc;
    int pos = was[hash] + rem;
    s = t;
    it = 0;
    last = 0;
    while (it < pos) {
      for (int i = last; i + 1 < s.length(); ++i)
        if (s[i] == '4' && s[i + 1] == '7') {
          if (i % 2 == 0) {
            s[i] = s[i + 1] = '4';
            last = i + 1;
          } else {
            s[i] = s[i + 1] = '7';
            last = i - 1;
            if (last < 0) last = 0;
          }
          break;
        }
      ++it;
    }
    cout << s << endl;
  }
  return 0;
}
