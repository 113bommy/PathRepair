#include <bits/stdc++.h>
using namespace std;
double const eps = 1e-6;
const int inf = 0x3fffffff;
const int size = 100000 + 5;
int sz;
map<string, int> cnt;
int day[13] = {-1, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
bool valid(int y, int m, int d) {
  if (y < 2013 || y > 2015) return false;
  if (m < 1 || m > 12) return false;
  if (d < 1 || d > day[m]) return false;
  return true;
}
int mx;
string ans;
void take(string str, int k) {
  for (int i = 0; i < (int)str.size(); i++)
    if (str[i] == '-' && i != 2 && i != 5) return;
  const char* s = str.c_str();
  int y, m, d;
  sscanf(s, "%d-%d-%d", &d, &m, &y);
  if (valid(y, m, d)) {
    if (cnt.find(str) == cnt.end())
      cnt[str] = 1;
    else
      cnt[str]++;
    if (cnt[str] > mx) {
      mx = cnt[str];
      ans = str;
    }
  }
}
int main() {
  string str;
  cin >> str;
  sz = str.size();
  for (int i = 0; i <= sz - 10; i++)
    if (str[i + 2] == '-') {
      take(str.substr(i, 10), i);
    }
  cout << ans << endl;
  return 0;
}
