#include <bits/stdc++.h>
using namespace std;
const int maxN = 1000 + 5;
const int mod = 1000 * 1000 * 1000 + 7;
int days[] = {31, 29, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
int num(string s) {
  int res = 0;
  for (int i = 0; i < ((int)(s).size()); i++) {
    if (s[i] < '0' || s[i] > '9') return -1;
    res = res * 10 + s[i] - '0';
  }
  return res;
}
bool valid(string s) {
  if (s[2] != '-' || s[5] != '-') return 0;
  int d = num(s.substr(0, 2)), m = num(s.substr(3, 2)), y = num(s.substr(6));
  if (y < 2013 || y > 2015) return 0;
  if (m < 1 || m > 12) return 0;
  if (d < 1 || d > days[m - 1]) return 0;
  return 1;
}
int main() {
  ios_base::sync_with_stdio(false);
  string s;
  cin >> s;
  map<string, int> d;
  for (int i = 0; i < ((int)(s).size()) - 9; i++) {
    string dt = s.substr(i, 10);
    d[dt] += valid(dt);
  }
  string out;
  int maxx = 0;
  for (__typeof(d.begin()) it = d.begin(); it != d.end(); it++)
    if (it->second > maxx) {
      maxx = it->second;
      out = it->first;
    }
  cout << out << endl;
  return 0;
}
