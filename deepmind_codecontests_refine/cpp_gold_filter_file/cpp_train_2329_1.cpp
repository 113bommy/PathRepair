#include <bits/stdc++.h>
using namespace std;
long long gcd(long long a, long long b) { return b ? gcd(b, a % b) : a; }
bool cmp1(pair<long long, long long> p1, pair<long long, long long> p2) {
  if (p1.first == p2.first) return p1.second < p2.second;
  return abs(p1.first - p1.second) < abs(p2.first - p2.second);
}
bool check(string str) {
  set<char> s;
  for (long long j = 0; j < str.size(); j++) s.insert(str[j]);
  return s.size() == 3;
}
int32_t main() {
  string str;
  cin >> str;
  long long countx = 0, county = 0;
  for (long long i = 0; i < str.size(); i++) {
    if (str[i] == 'x')
      countx++;
    else
      county++;
  }
  long long times = abs(countx - county);
  char c;
  if (countx > county)
    c = 'x';
  else
    c = 'y';
  for (long long i = 0; i < times; i++) cout << c;
  return 0;
}
