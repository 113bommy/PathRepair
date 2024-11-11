#include <bits/stdc++.h>
using namespace std;
void read_file(bool outToFile = true) {}
vector<int> p, d;
int n;
int tmp;
vector<int> to_vec(long long x) {
  vector<int> ret;
  while (x) ret.push_back(x % 10), x /= 10;
  reverse(((ret).begin()), ((ret).end()));
  return ret;
}
int ninesIn(vector<int> &v) {
  int idx = n - 1;
  while (idx >= 0 && v[idx] == 9) idx--;
  return n - 1 - idx;
}
bool isLess(vector<int> &l, vector<int> &r) { return ninesIn(l) < ninesIn(r); }
bool isEqual(vector<int> &l, vector<int> &r) {
  return !isLess(l, r) && !isLess(r, l);
}
void upd(vector<int> &ans, vector<int> &vec) {
  if (d <= vec && vec <= p &&
      (isLess(ans, vec) || isEqual(ans, vec) && ans < vec))
    ans = vec;
}
int main() {
  read_file();
  long long pp, dd;
  while (cin >> pp >> dd) {
    dd = pp - dd;
    p = to_vec(pp);
    d = to_vec(dd);
    n = p.size();
    while (d.size() != n) d.insert(d.begin(), 0);
    vector<int> ans = p;
    vector<int> vec(n, 9);
    int idx = 0;
    while (idx != n) {
      for (int i = p[idx]; i >= 0; i--) {
        vec[idx] = i;
        upd(ans, vec);
      }
      vec[idx] = p[idx];
      idx++;
    }
    idx = 0;
    while (idx < n && ans[idx] == 0) idx++;
    if (idx == n) idx = n - 1;
    for (int i = idx; i < n; i++) cout << ans[i];
    cout << '\n';
  }
}
