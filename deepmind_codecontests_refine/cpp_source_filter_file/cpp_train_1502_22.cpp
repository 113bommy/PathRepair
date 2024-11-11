#include <bits/stdc++.h>
using namespace std;
int main() {
  long long int b, second, c, nb, ns, nc, push_back, ps, pc, n, i, r;
  b = second = c = 0;
  string str;
  cin >> str;
  n = str.size();
  for (i = 0; i < n; i++) {
    if (str[i] == 'B') {
      b++;
    }
    if (str[i] == 'S') {
      second++;
    }
    if (str[i] == 'C') {
      c++;
    }
  }
  vector<pair<int, pair<int, int> > > v(3);
  cin >> nb >> ns >> nc;
  v[0].first = nb;
  v[1].first = ns;
  v[2].first = nc;
  cin >> push_back >> ps >> pc;
  cin >> r;
  v[0].second.first = push_back;
  v[1].second.first = ps;
  v[2].second.first = pc;
  v[0].second.second = b;
  v[1].second.second = second;
  v[2].second.second = c;
  sort(v.begin(), v.end());
  long long int lt = 0, rt = 1000050000000, m, k, req, ans;
  while (lt < rt) {
    int first = 0, f1 = 0;
    m = (lt + rt) / 2;
    if (v[0].second.second != 0) {
      k = m * v[0].second.first;
      req = (v[0].first + m) / v[0].second.second;
    } else {
      if (v[1].second.second != 0) {
        first = 1;
        k = m * v[1].second.first;
        req = (v[1].first + m) / v[1].second.second;
      } else {
        f1 = 1;
        k = m * v[2].second.first;
        req = (v[2].first + m) / v[2].second.second;
      }
    }
    if (v[1].second.second > 0 && (v[1].first) / v[1].second.second < req) {
      if (first == 0)
        k = k + (req * v[1].second.second - v[1].first) * v[1].second.first;
    }
    if (v[2].second.second > 0 && (v[2].first) / v[2].second.second < req) {
      if (f1 == 0)
        k = k + (req * v[2].second.second - v[2].first) * v[2].second.first;
    }
    if (k > r) {
      rt = m;
    } else {
      ans = req;
      lt = m + 1;
    }
  }
  cout << ans;
}
