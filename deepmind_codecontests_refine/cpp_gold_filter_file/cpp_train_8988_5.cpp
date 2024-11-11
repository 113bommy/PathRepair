#include <bits/stdc++.h>
using namespace std;
int n, m, ans[1000001], lf[200001], rg[200001];
set<pair<int, pair<int, int> > > s;
pair<int, pair<int, int> > f(int a, int b) {
  int len, l, r;
  if (a == 0 && b == n + 1)
    len = -1000000000, l = 0, r = 1;
  else if (a == 0)
    len = -(b - 1), l = 0, r = 1;
  else if (b == n + 1)
    len = -(n - a), l = a, r = n;
  else
    len = -(b - a) / 2, l = a, r = a + (b - a) / 2;
  return make_pair(len, make_pair(l, r));
}
int main() {
  int a, b, c;
  cin >> n >> m;
  lf[n + 1] = 0;
  rg[0] = n + 1;
  s.clear();
  s.insert(make_pair(-1000000000, make_pair(0, 1)));
  for (int i = 0; i < m; i++) {
    int t, num;
    cin >> t >> num;
    if (t == 1) {
      pair<int, int> aaa = (s.begin())->second;
      s.erase(s.begin());
      a = aaa.first;
      b = aaa.second;
      c = rg[aaa.first];
      ans[num] = b;
      lf[b] = a;
      lf[c] = b;
      rg[a] = b;
      rg[b] = c;
      s.insert(f(a, b));
      s.insert(f(b, c));
      cout << b << endl;
    } else {
      b = ans[num];
      a = lf[ans[num]];
      c = rg[ans[num]];
      s.erase(f(a, b));
      s.erase(f(b, c));
      rg[a] = c;
      lf[c] = a;
      s.insert(f(a, c));
    }
  }
  return 0;
}
