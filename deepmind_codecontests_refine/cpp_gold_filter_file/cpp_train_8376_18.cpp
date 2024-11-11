#include <bits/stdc++.h>
using namespace std;
int gcd(int a, int b) {
  if (b == 0)
    return a;
  else
    return gcd(b, a % b);
}
int cnk(long long n, long long k, long long mod) {
  long long result = 1;
  int lal = 0;
  for (int lol = n; lal < k; lal++, lol--) {
    result *= lol;
    result %= mod;
  }
  return result;
}
const long long mod = 1e9 + 7;
vector<long long> graph[100000];
vector<long long> vec;
vector<pair<pair<int, int>, int> > vec3;
long long log4(long long val) {
  long long lol = 1;
  long long ii = 0;
  if (val == 1) {
    return 1;
  }
  while (lol < val) {
    ii++;
    lol *= 4;
  }
  return ii;
}
bool comp(pair<pair<int, int>, int> a, pair<pair<int, int>, int> b) {
  return a.first.first > b.first.first;
}
string tostr(long long a) {
  ostringstream out;
  out << a;
  return out.str();
}
long long power(long long a, long long b) {
  if (b == 0) return 1;
  if (b % 2 == 0) {
    return power(a, b / 2) * power(a, b / 2);
  } else
    return a * power(a, b - 1);
}
long long tobig(string str) {
  long long res = 0;
  for (long long lol = 0; lol < str.size(); lol++) {
    res += (str[lol] - 48) * power(10, str.size() - 1 - lol);
  }
  return res;
}
map<char, int> tz;
vector<pair<int, int> > vec2;
vector<long long> ans[105];
long long mas[30][30];
int sum(string s) {
  int res = 0;
  for (int lol = 0; lol < s.length(); lol++) {
    res += s[lol] - 48;
  }
  return res;
}
int main() {
  string s, s1, s2;
  int n, m, k, k1, k2;
  cin >> n;
  string last = "0";
  int lass = 0, diap;
  for (int lol = 0; lol < n; lol++) {
    cin >> k;
    diap = 0;
    int deist = last.length() - 1;
    while (deist >= 0) {
      int chi = last[deist] - 48;
      if (chi == 9) {
        deist--;
        diap += 9;
        continue;
      }
      if (9 + diap + sum(last.substr(0, deist)) >= k &&
          sum(last.substr(0, deist)) + chi + 1 <= k) {
        int razn = k - sum(last.substr(0, deist + 1));
        last[deist]++;
        razn--;
        for (int lal = last.length() - 1; lal > deist; lal--) {
          last[lal] = 48 + min(9, razn);
          razn -= min(9, razn);
        }
        last[deist] += razn;
        break;
      }
      deist--;
      if (deist == -1) {
        deist = 0;
        last = "0" + last;
      }
      diap += 9;
    }
    if (last[0] != '0') {
      cout << last << "\n";
      last = "0" + last;
    } else
      cout << last.substr(1, last.length() - 1) << "\n";
  }
  return 0;
}
