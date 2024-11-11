#include <bits/stdc++.h>
using namespace std;
void pl(long long a) { printf("%lld\n", a); }
void pll(long long a, long long b) { printf("%lld %lld\n", a, b); }
void plll(long long a, long long b, long long c) {
  printf("%lld %lld %lld\n", a, b, c);
}
void sss(string s) { cout << s, printf("\n"); }
long long string_to_ll(string s) {
  stringstream ss;
  ss << s;
  long long n;
  ss >> n;
  return n;
}
string ll_to_string(long long n) {
  stringstream ss;
  ss << n;
  string s;
  ss >> s;
  return s;
}
string s, s1;
int compare_big_number(string s1, string s2) {
  string a, b;
  long long i, aa, bb;
  if (s1.size() > s2.size()) {
    aa = s1.size() - s2.size();
    for (long long i = (long long)0; i < (long long)aa; i++) a += '0';
  } else {
    bb = s2.size() - s1.size();
    for (long long i = (long long)0; i < (long long)bb; i++) b += '0';
  }
  a += s2;
  b += s1;
  if (a == b)
    return 0;
  else if (a > b)
    return 1;
  a.clear(), b.clear(), s1.clear(), s2.clear();
}
int main() {
  cin >> s >> s1;
  if (!compare_big_number(s, s1))
    sss(s);
  else
    sss(s);
  return 0;
}
