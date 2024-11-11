#include <bits/stdc++.h>
using namespace std;
struct str {
  int len;
  int ind;
  str(int l, int i) {
    len = l;
    ind = i;
  }
  str() {}
};
bool cmp(const str &a, const str &b) { return a.len < b.len; }
bool operator<(const str &a, const str &b) { return a.len < b.len; }
int main() {
  istream &in = cin;
  int n, m;
  in >> n >> m;
  vector<int> x(n), y(n);
  for (int i = 0; i < n; i++) in >> x[i] >> y[i];
  vector<str> lens(m);
  for (int i = 0; i < m; i++) {
    in >> lens[i].len;
    lens[i].ind = i + 1;
  }
  lens.push_back(str(INT_MAX, n + 1));
  lens.push_back(str(-INT_MAX, 0));
  sort(lens.begin(), lens.end(), cmp);
  vector<char> used(n + 2, false);
  vector<int> res(n + 2, -1);
  for (int start = 0; start < n; start++) {
    int a, b, c;
    a = start % n;
    b = (a + 1) % n;
    c = (a + 2) % n;
    bool ok = true;
    used.clear();
    used.resize(n + 2, false);
    res.clear();
    res.resize(n, -1);
    for (int k = 0; k < n / 2; k++) {
      int ab = abs(x[a] - x[b]) + abs(y[a] - y[b]);
      int bc = abs(x[b] - x[c]) + abs(y[b] - y[c]);
      int d = ab + bc;
      vector<str>::iterator low =
          lower_bound(lens.begin(), lens.end(), str(d, -1));
      if (low->len != d) {
        ok = false;
        break;
      }
      ok = false;
      int choosed = -1;
      while (low->len == d) {
        int ind = low->ind;
        if (!used[ind]) {
          used[ind] = true;
          choosed = ind;
          ok = true;
          break;
        }
        low++;
      }
      if (!ok) break;
      res[b] = choosed;
      a = c;
      b = a + 1;
      c = a + 2;
      a %= n;
      b %= n;
      c %= n;
    }
    if (ok) {
      cout << "YES" << endl;
      for (int i = 0; i < n; i++) cout << res[i] << " ";
      return 0;
    }
  }
  cout << "NO";
  return 0;
}
