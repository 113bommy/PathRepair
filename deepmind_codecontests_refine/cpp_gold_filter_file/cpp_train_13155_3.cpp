#include <bits/stdc++.h>
using namespace std;
const double pi = acos(-1.0);
const double eps = 1e-8;
template <class T>
inline void read(T &i) {
  bool minus = false;
  char c;
  for (c = getchar(); (c < '0' || c > '9') && (c != '-'); c = getchar())
    ;
  if (c == '-') {
    minus = true;
    c = '0';
  }
  for (i = 0; c >= '0' && c <= '9'; c = getchar())
    i = (i << 3) + (i << 1) + (c - 48);
  if (minus) i = (~i) + 1;
}
int gcd(int a, int b) {
  if (a == b) return b;
  if (b < a) return gcd(a % b, b);
  return gcd(a, b % a);
}
vector<string> parse(string s, string c) {
  int len = c.length(), p = -len, np;
  vector<string> ans;
  do {
    np = s.find(c, p + len);
    ans.push_back(s.substr(p + len, np - p - len));
    p = np;
  } while (p != string::npos);
  return ans;
}
int main() {
  int n, x, y;
  cin >> n;
  priority_queue<pair<int, int> > q[2];
  for (int i = 1; i <= n; i++) {
    cin >> x >> y;
    q[x].push(make_pair(-y, i));
  }
  for (int i = 1; i <= n - 1; i++) {
    pair<int, int> p1 = q[0].top(), p2 = q[1].top();
    q[0].pop();
    q[1].pop();
    x = -p1.first;
    y = -p2.first;
    cout << p1.second << " " << p2.second << " " << min(x, y) << endl;
    ;
    if ((x > y && (not q[1].empty())) || q[0].empty())
      q[0].push(make_pair(-(x - y), p1.second));
    else
      q[1].push(make_pair(-(y - x), p2.second));
  }
  return 0;
}
