#include <bits/stdc++.h>
using namespace std;
const long long inf = 1e18;
const int N = 1e6 + 10;
long long mod = 1e9 + 7;
const int base = 131;
const double pi = acos(-1);
const double eps = 1e-8;
inline long long ksm(long long a, long long b) {
  long long ans = 1;
  while (b) {
    if (b & 1) ans = ans * a % mod;
    a = a * a % mod, b >>= 1;
  }
  return ans;
}
long long vis[N], num[N];
long long n, m, k, x, y, z;
long long a[N], b[N], c[N];
long long cx, cy, cnt, ans, sum, flag, t, ff, q;
vector<int> v[N];
unordered_map<int, int> mp;
set<string> st;
string s;
int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int a = 1, b = 0;
  getline(cin, s);
  for (int i = 0; s[i]; i++) {
    if (s[i] == '+') a++;
    if (s[i] == '-') b++;
    if (isdigit(s[i])) {
      n = n * 10 + s[i] - '0';
    }
  }
  if (a > n + b * n || a * n - b < n)
    cout << "Impossible" << endl;
  else {
    cout << "Possible" << endl;
    t = (n + b) / a;
    x = (n + b) % a;
    y = a - x;
    int pos = t, neg = 1;
    if ((t + 1 > n && x >= 1) || (t > n) || t <= 0) {
      t = (n + b * n) / a;
      ;
      x = (n + b * n) % a;
      y = a - x;
      pos = t;
      neg = n;
    }
    for (int i = 0; s[i]; i++) {
      if (s[i] == '?') {
        if (i == 0) {
          if (x >= 1)
            x--, cout << pos + 1;
          else if (y)
            y--, cout << pos;
        } else {
          if (s[i - 2] == '+') {
            if (x >= 1)
              x--, cout << pos + 1;
            else if (y)
              y--, cout << pos;
          }
          if (s[i - 2] == '-') {
            cout << neg;
          }
        }
      } else
        cout << s[i];
    }
  }
}
