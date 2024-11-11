#include <bits/stdc++.h>
using namespace std;
double const pi = 3.1415926535897932384626433832795;
int const inf = (int)1e9;
long long const inf64 = (long long)2e18;
const string name = "b";
int n;
string a, b, s;
map<string, pair<int, int> > M;
int main() {
  cin >> n;
  M["void"] = make_pair(0, 0);
  M["errtype"] = make_pair(-1, -1);
  for (int i = 0; i < (int)n; i++) {
    cin >> s;
    if (s[4] == 'd') {
      cin >> a >> b;
      int x, y, xx = a.length(), yy = a.length();
      for (int i = 0; i < (int)a.length(); i++)
        if (a[i] != '&') {
          xx = i;
          break;
        }
      for (int i = a.length() - 1; i >= 0; --i)
        if (a[i] != '*') {
          yy = a.length() - i - 1;
          break;
        }
      if (!M.count(a.substr(xx, a.length() - xx - yy))) {
        M[a.substr(xx, a.length() - xx - yy)] = make_pair(-1, -1);
        continue;
      }
      x = M[a.substr(xx, a.length() - xx - yy)].first;
      y = M[a.substr(xx, a.length() - xx - yy)].second;
      int d = min(x + xx, y + yy);
      if (x == -1 || y == -1 || x + xx > y + yy)
        M[b] = make_pair(-1, -1);
      else
        M[b] = make_pair(x + xx - d, y + yy - d);
    } else {
      cin >> a;
      int x, y, xx = a.length(), yy = a.length();
      for (int i = 0; i < (int)a.length(); i++)
        if (a[i] != '&') {
          xx = i;
          break;
        }
      for (int i = a.length() - 1; i >= 0; --i)
        if (a[i] != '*') {
          yy = a.length() - i - 1;
          break;
        }
      a = a.substr(xx, a.length() - xx - yy);
      if (!M.count(a) || M[a] == make_pair(-1, -1) ||
          M[a].first + xx > M[a].second + yy)
        cout << "errtype" << endl;
      else {
        int x = M[a].first + xx, y = M[a].second + yy;
        int d = min(x, y);
        x -= d, y -= d;
        for (int i = 0; i < (int)x; i++) printf("&");
        cout << "void";
        for (int i = 0; i < (int)y; i++) printf("*");
        cout << endl;
      }
    }
  }
  return 0;
}
