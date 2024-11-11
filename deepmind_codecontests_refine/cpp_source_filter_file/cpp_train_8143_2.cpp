#include <bits/stdc++.h>
using namespace std;
string s, q;
long long sum, u, h;
pair<char, string> p[8];
long long mypower(long long b, long long p, long long m) {
  if (p == 0) return 1;
  if (p % 2 == 0) {
    long long temp = mypower(b, p / 2, m);
    return (temp * temp) % m;
  }
  return (mypower(b, p - 1, m) * (b % m)) % m;
}
long long btd(string q) {
  for (int j = (q.length() - 1); j >= 0; j--) {
    if (q[j] == '1') {
      sum = (mypower(2, u, 1000003) + sum % 1000003) % 1000003;
    }
    u++;
  }
  return sum;
}
int main() {
  p[0].first = '>';
  p[0].second = "0000";
  p[1].first = '<';
  p[1].second = "1001";
  p[2].first = '+';
  p[2].second = "1010";
  p[3].first = '-';
  p[3].second = "1011";
  p[4].first = '.';
  p[4].second = "1100";
  p[5].first = ',';
  p[5].second = "1101";
  p[6].first = '[';
  p[6].second = "1110";
  p[7].first = ']';
  p[7].second = "1111";
  cin >> s;
  for (int i = 0; i < s.length(); i++) {
    for (int j = 0; j < 8; j++) {
      if (s[i] == p[j].first) {
        q += p[j].second;
      }
    }
  }
  cout << btd(q);
  return 0;
}
