#include <bits/stdc++.h>
using namespace std;
string en = "\n";
string t = "hello";
string Y = "YES\n";
string N = "NO\n";
bool isprm(long long a) {
  for (long long i = 2; i * i <= a; i++) {
    if (a % i == 0) return false;
  }
  return true;
}
bool palin(string a) {
  for (int i = 0; i < a.size(); i++) {
    if (a.at(i) != a.at(a.size() - i - 1)) return 0;
  }
  return 1;
}
bool isVowel(char ch) {
  ch = toupper(ch);
  if (ch == 'A' || ch == 'U' || ch == 'I' || ch == 'O' || ch == 'E')
    return true;
  return false;
}
int toInt(string s) {
  int sm;
  stringstream ss(s);
  ss >> sm;
  return sm;
}
long long bpow(long long a, long long b) {
  if (b == 0) return 1;
  long long r = bpow(a, b / 2);
  if (b % 2)
    return r * r * a;
  else
    return r * r;
}
long long binpow(long long a, long long b) {
  long long r = 1;
  while (b > 0) {
    if (b & 1) r = r * a;
    a = a * a;
    b >>= 1;
  }
  return r;
}
long long binpow(long long a, long long b, long long m) {
  a %= m;
  long long r = 1;
  while (b > 0) {
    if (b & 1) r = r * a % m;
    a = a * a % m;
    b >>= 1;
  }
  return r;
}
template <typename T>
inline T gcd(T a, T b) {
  if (a < 0) return gcd(-a, b);
  if (b < 0) return gcd(a, -b);
  return (b == 0) ? a : gcd(b, a % b);
}
template <typename T>
inline T lcm(T a, T b) {
  if (a < 0) return lcm(-a, b);
  if (b < 0) return lcm(a, -b);
  return a * (b / gcd(a, b));
}
int main() {
  long long i, j, k, n, m, l, s = 0, x, y, p, q, tc = 1, a, b, c = 0;
  string st;
  while (cin >> st >> q) {
    char ch, chr;
    set<char> ss[26];
    for (i = 0; i < st.size(); i++) {
      ss[st.at(i) - 'a'].insert(i + 1);
    }
    while (q--) {
      cin >> x;
      if (x == 1) {
        cin >> p >> ch;
        chr = st.at(p - 1);
        st.at(p - 1) = ch;
        ss[chr - 'a'].erase(p);
        ss[ch - 'a'].insert(p);
      } else {
        cin >> x >> y;
        c = 0;
        for (i = 0; i < 26; i++) {
          auto it = ss[i].lower_bound(x);
          if (it == ss[i].end()) continue;
          l = *it;
          if (l <= y) {
            ch = i + 'a';
            c++;
          }
        }
        cout << c << en;
      }
    }
  }
}
