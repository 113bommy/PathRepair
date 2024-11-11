#include <bits/stdc++.h>
using namespace std;
string en = "\n";
string hlo = "hello";
string Y = "YES\n";
string Ys = "Yes\n";
string N = "NO\n";
string No = "No\n";
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
int main() {
  long long a, b, c, d, e, x, t, n, k, m, p, q, r, y, z, yy, sum = 0, ct = 0,
                                                             flag = 0;
  string s, s1, s2, s3, s4;
  char ch;
  deque<char> d1, d2, d3;
  vector<long long> v1, v2, v3;
  map<char, long long> mp;
  map<long long, long long>::iterator it;
  set<char> st1, st2;
  vector<pair<long long, long long> > v;
  double x1, y1, x2, y2, x3, y3, x4, y4;
  sum = 0;
  long long mx = 0, mn = 3487327628458454875, cp = 0;
  long long j = 0, HR, MN, mnt, hrs, c1 = 0, c2 = 0;
  flag = 0;
  cin >> s;
  flag = 0;
  for (long long i = 0; i < s.size(); i++) {
    if (s[i] == 'o')
      c1++;
    else
      c2++;
  }
  if (c1 == 0) {
    cout << Y;
    return 0;
  }
  if (c2 % c1 == 0)
    cout << Y;
  else
    cout << N;
}
