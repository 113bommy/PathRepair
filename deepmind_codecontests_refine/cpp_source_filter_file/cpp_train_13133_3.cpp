#include <bits/stdc++.h>
using namespace std;
vector<string> p, t;
vector<string> otv;
vector<pair<string, string> > v;
long n, m;
void f(long pos, long next = 0) {
  if (pos == n) {
    if (otv.size() < next) {
      otv = t;
      otv.resize(next);
    }
    return;
  }
  bool ff = true;
  long i, j;
  for (i = 0; i < pos; i++) {
    for (j = 0; j < m; j++)
      if (v[j] == make_pair(p[i], p[pos]) || v[j] == make_pair(p[pos], p[i]))
        ff = false;
    if (!ff) break;
  }
  if (ff) {
    t[next] = p[pos];
    f(pos + 1, next + 1);
  }
  f(pos + 1, next);
}
int main() {
  cin >> n >> m;
  p.resize(n);
  t.resize(n);
  v.resize(m);
  long i;
  for (i = 0; i < n; i++) cin >> p[i];
  for (i = 0; i < m; i++) cin >> v[i].first >> v[i].second;
  f(0);
  cout << otv.size() << endl;
  sort(otv.begin(), otv.end());
  for (i = 0; i < otv.size(); i++) cout << otv[i] << endl;
  return 0;
}
