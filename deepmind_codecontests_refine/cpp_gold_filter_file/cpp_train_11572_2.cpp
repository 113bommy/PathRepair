#include <bits/stdc++.h>
using namespace std;
const long long base = 7;
const long long maxn = 1e6 + 9;
const long long inf = 1e9 + 7;
queue<long long> l[30], r[30], l1, r1, lf, rf;
vector<pair<long long, long long> > res;
long long n, i;
string a, b;
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  cin >> n >> a >> b;
  a = " " + a;
  b = " " + b;
  for (i = 1; i <= n; i++) {
    if (a[i] != '?')
      l[a[i] - 'a'].push(i);
    else
      l1.push(i);
  }
  for (i = 1; i <= n; i++) {
    if (b[i] != '?')
      r[b[i] - 'a'].push(i);
    else
      r1.push(i);
  }
  for (i = 0; i <= 27; i++) {
    while (true) {
      if (!l[i].empty() && !r[i].empty()) {
        res.push_back(make_pair(l[i].front(), r[i].front()));
        l[i].pop();
        r[i].pop();
      } else {
        while (!l[i].empty()) {
          lf.push(l[i].front());
          l[i].pop();
        }
        while (!r[i].empty()) {
          rf.push(r[i].front());
          r[i].pop();
        }
        break;
      }
    }
  }
  while (true) {
    if (!lf.empty() && !r1.empty()) {
      res.push_back(make_pair(lf.front(), r1.front()));
      lf.pop();
      r1.pop();
    } else
      break;
  }
  while (true) {
    if (!rf.empty() && !l1.empty()) {
      res.push_back(make_pair(l1.front(), rf.front()));
      rf.pop();
      l1.pop();
    } else
      break;
  }
  while (true) {
    if (!r1.empty() && !l1.empty()) {
      res.push_back(make_pair(l1.front(), r1.front()));
      r1.pop();
      l1.pop();
    } else
      break;
  }
  cout << res.size() << "\n";
  for (i = 0; i < res.size(); i++)
    cout << res[i].first << " " << res[i].second << "\n";
}
