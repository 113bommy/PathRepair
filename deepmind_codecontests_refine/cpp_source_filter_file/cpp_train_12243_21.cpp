#include <bits/stdc++.h>
using namespace std;
const int INF = 1e9 + 10;
const int MOD = 1e9 + 7;
const int MAXN = 1e6 + 10;
const int SMAXN = 1e3 + 10;
const int P = 259;
const long long BINF = 1e18 + 10;
const long double EPS = 1e-10;
const long double PI = acos(-1);
inline void error() {
  cout << -1;
  exit(0);
}
int n, m, ans, cnt, sum, a, h;
vector<int> Vec, arr;
string s;
bool check() {
  stringstream str;
  string s, s1;
  str << h;
  str >> s;
  str.clear();
  str << m;
  str >> s1;
  if (s.size() < 2) s.insert(s.begin(), '0');
  if (s1.size() < 2) s1.insert(s1.begin(), '0');
  s += s1;
  return (s[0] == s[3] && s[1] == s[2]);
}
void inc() {
  if (m < 60)
    m++;
  else {
    m = 0;
    h++;
    h %= 24;
  }
}
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  srand(time(0));
  cin >> s;
  h = (s[0] - 48) * 10 + s[1] - 48;
  m = (s[3] - 48) * 10 + s[4] - 48;
  while (!check()) {
    inc();
    ans++;
  }
  cout << ans;
  return 0;
}
