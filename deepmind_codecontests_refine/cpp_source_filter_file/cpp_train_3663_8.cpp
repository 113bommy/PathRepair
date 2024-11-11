#include <bits/stdc++.h>
using namespace std;
map<long long, long long> M;
vector<pair<long long, long long> > V;
long long a, b, c, d, e, f, g, h, i, j, k, l, m, n, o, p, q, r, s, t, u, v, w,
    x, y, z, x1, x2, x3, x4, x5, x6, y11, y2, y3, y4, y5, y6, s1, s2;
pair<long long, long long> P;
string st;
bool cmp(pair<long long, long long> p1, pair<long long, long long> p2) {
  return p1.first >= p2.first;
}
int main() {
  s = 0;
  cin >> n;
  for (i = 1; i <= n; i++) {
    cin >> P.first;
    P.second = i;
    V.push_back(P);
  }
  sort(V.begin(), V.end(), cmp);
  for (i = 0; i < n; i++) {
    s += V[i].first * i;
  }
  cout << s + n << endl;
  for (i = 0; i < n; i++) cout << V[i].second << ' ';
  return 0;
}
