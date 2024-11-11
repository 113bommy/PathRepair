#include <bits/stdc++.h>
using namespace std;
int main() {
  cin.tie(0);
  ios_base::sync_with_stdio(0);
  int n;
  cin >> n;
  auto query = [&](int a, int b) {
    static map<pair<int, int>, int> m;
    if (b < a) swap(a, b);
    if (!m.count({a, b})) {
      cout << a + 1 << " " << b + 1 << endl;
      int& res = m[{a, b}];
      cin >> res;
      return res;
    }
    return m[{a, b}];
  };
  vector<int> z(11, -1);
  for (int v = 0; v < 11;) {
    int a = rand() % n;
    int b = rand() % (n - 1);
    b = (a + b + 1) % n;
    int res = query(a, b);
    for (int k = 0; k < 11; k++) {
      if (z[k] < 0 && !((res >> k) & 1)) {
        z[k] = a;
        v++;
      }
    }
  }
  auto calc = [&](int i) {
    int res = 0;
    map<int, int> m;
    for (int k = 0; k < 11; k++) {
      if (!m.count(z[k])) m[z[k]] = i == z[k] ? 0 : query(i, z[k]);
      res |= m[z[k]] & (1 << k);
    }
    return res;
  };
  vector<int> p(n, -1);
  int cand = 0;
  p[cand] = calc(cand);
  for (int i = 1; i < n; i++) {
    int res = query(cand, i);
    if ((res & p[cand]) == res) {
      cand = i;
      p[cand] = calc(cand);
    }
  }
  for (int i = 0; i < n; i++)
    if (p[i] < 0) p[i] = query(cand, i);
  cout << "!";
  for (int i = 0; i < n; i++) cout << " " << p[i];
  cout << "\n";
  return 0;
}
