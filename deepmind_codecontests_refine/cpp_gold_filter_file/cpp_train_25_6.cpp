#include <bits/stdc++.h>
using namespace std;
bool db = false;
const long long INF = 1e18 + 100;
const long long MOD = 1e9 + 7;
const long long maxn = 2 * 1e6 + 1;
long long t, n, m, x, k, q;
long long a, b, c, d;
pair<long long, long long> pa, pb, pc, pd;
long long ans = 0;
string s[200];
vector<pair<long long, long long> > v;
int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  cin >> t;
  while (t--) {
    cin >> n;
    for (int i = 0; i < n; i++) {
      cin >> s[i];
    }
    a = (s[1][0] == '1');
    b = (s[0][1] == '1');
    c = (s[n - 1][n - 2] == '1');
    d = (s[n - 2][n - 1] == '1');
    if (db) {
      cout << "a: " << a << endl;
      cout << "b: " << b << endl;
      cout << "c: " << c << endl;
      cout << "d: " << d << endl;
      cout << endl;
    }
    pa = {1, 0};
    pb = {0, 1};
    pc = {n - 1, n - 2};
    pd = {n - 2, n - 1};
    ans = 0;
    v.clear();
    if (a == 0 and b == 0) {
      if (c == 0) v.push_back(pc);
      if (d == 0) v.push_back(pd);
    } else if (a == 1 and b == 1) {
      if (c == 1) v.push_back(pc);
      if (d == 1) v.push_back(pd);
    } else if (a == 0 and b == 1) {
      if (c == 0 and d == 0) {
        v.push_back(pa);
      } else if (c == 0 and d == 1) {
        v.push_back(pb);
        v.push_back(pc);
      } else if (c == 1 and d == 0) {
        v.push_back(pb);
        v.push_back(pd);
      } else if (c == 1 and d == 1) {
        v.push_back(pb);
      }
    } else if (a == 1 and b == 0) {
      if (c == 0 and d == 0) {
        v.push_back(pb);
      } else if (c == 0 and d == 1) {
        v.push_back(pb);
        v.push_back(pd);
      } else if (c == 1 and d == 0) {
        v.push_back(pb);
        v.push_back(pc);
      } else if (c == 1 and d == 1) {
        v.push_back(pa);
      }
    }
    ans = v.size();
    cout << ans << endl;
    for (auto xy : v) {
      cout << xy.first + 1 << " " << xy.second + 1 << endl;
    }
    if (db) {
      cout << endl << endl;
    }
  }
  return 0;
}
