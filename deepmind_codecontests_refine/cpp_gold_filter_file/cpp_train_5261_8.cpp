#include <bits/stdc++.h>
using namespace std;
struct pnt {
  long long st, nd, id;
};
bool operator<(pnt a, pnt b) { return a.st < b.st; }
long long res[4000100] = {0}, prg[4000100] = {0};
long long r, l, pos, val;
void updt(long long x, long long st, long long nd) {
  if (st >= l && nd <= r) {
    prg[x] += val;
    return;
  }
  if (st > r) {
    return;
  }
  long long mid = (st + nd) / 2;
  updt(x * 2, st, mid);
  updt(x * 2 + 1, mid + 1, nd);
}
long long qry(long long x, long long st, long long nd) {
  if (st > pos || nd < pos) {
    return 0;
  }
  if (st == nd) {
    return prg[x];
  }
  prg[x * 2] += prg[x];
  prg[x * 2 + 1] += prg[x];
  prg[x] = 0;
  long long mid = (st + nd) / 2;
  return qry(x * 2, st, mid) + qry(x * 2 + 1, mid + 1, nd);
}
vector<pnt> v;
vector<long long> v1;
map<long long, long long> m;
int main() {
  long long n, cnt = 2, x, y, z;
  pnt tmp;
  cin >> n;
  for (long long i = 0; i < n; ++i) {
    cin >> x >> y;
    tmp.st = x;
    tmp.nd = y;
    tmp.id = i;
    v.push_back(tmp);
    tmp.st = y;
    tmp.nd = x;
    tmp.id = i;
    v.push_back(tmp);
    v1.push_back(x);
    v1.push_back(y);
  }
  sort(v1.begin(), v1.end());
  for (long long i = 0; i < v1.size(); ++i) {
    m[v1[i]] = cnt++;
  }
  sort(v.begin(), v.end());
  for (long long i = 0; i < v.size(); ++i) {
    x = v[i].st;
    y = v[i].nd;
    if (x > y) {
      z = m[y] - 1;
      l = 1;
      r = z;
      val = 1;
      updt(1, 1, cnt - 1);
      pos = z + 1;
      res[v[i].id] = qry(1, 1, cnt - 1);
    }
  }
  for (long long i = 0; i < n; ++i) {
    cout << res[i] << endl;
  }
  return 0;
}
