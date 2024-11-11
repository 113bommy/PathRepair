#include <bits/stdc++.h>
using namespace std;
bool check(pair<int, string> a, pair<int, string> b) {
  return a.first > b.first;
}
int main() {
  long long int a, b, c, m, x, i, cost = 0, count = 0;
  vector<pair<int, string> > p, q;
  string s;
  cin >> a >> b >> c >> m;
  for (i = 0; i < m; i++) {
    cin >> x >> s;
    if (s == "USB")
      p.push_back(make_pair(x, s));
    else
      q.push_back(make_pair(x, s));
  }
  stable_sort(p.begin(), p.end(), check);
  stable_sort(q.begin(), q.end(), check);
  vector<pair<int, string> >::iterator it = p.end(), yo;
top:
  it = p.end();
  for (it--; !p.empty() && a != 0;) {
    cost += it->first;
    p.pop_back();
    count++;
    a--;
    goto top;
  }
next:
  it = q.end();
  for (it--; !q.empty() && b != 0;) {
    cost += it->first;
    q.pop_back();
    count++;
    b--;
    goto next;
  }
again:
  it = p.end();
  yo = q.end();
  for (it--, yo--; ((!p.empty()) || (!q.empty())) && c != 0;) {
    if (!p.empty() && !q.empty()) {
      if (it->first > yo->first) {
        cost += it->first;
        q.pop_back();
        count++;
      } else {
        cost += yo->first;
        p.pop_back();
        count++;
      }
    } else {
      if (p.empty()) {
        cost += yo->first;
        q.pop_back();
        count++;
      } else {
        cost += it->first;
        p.pop_back();
        count++;
      }
    }
    c--;
    goto again;
  }
  cout << count << " " << cost;
}
