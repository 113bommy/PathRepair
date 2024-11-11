#include <bits/stdc++.h>
using namespace std;
const long long mod = 1e9 + 7;
const long long INF = 0x3f3f3f3f3f3f3f3f;
const int maxn = 1 << 20;
int n, m, q, s, a, b;
vector<int> c;
struct dis {
  int p[maxn], c[maxn];
  void init(int n) {
    for (int i = (int)(0); i < (int)(n); i++) {
      p[i] = i;
      c[i] = 1;
    }
  }
  int root(int i) { return i == p[i] ? i : (p[i] = root(p[i])); }
  void setp(int i, int j) {
    i = root(i);
    j = root(j);
    if (i == j) return;
    if (c[i] > c[j]) swap(i, j);
    p[i] = j;
    c[j] += c[i];
  }
} ds;
int main() {
  scanf("%d%d%d", &n, &q, &m);
  ds.init(n);
  for (int i = (int)(0); i < (int)(q); i++) {
    scanf("&d&d", &a, &b);
    ds.setp(a - 1, b - 1);
  }
  for (int i = (int)(0); i < (int)(n); i++)
    if (ds.root(i) == i) c.push_back(ds.c[i]);
  if (c.size() == 1)
    cout << 0 << endl;
  else if (m == 1)
    cout << max(0, (int)c.size() - 2) << endl;
  else {
    q = count(c.begin(), c.end(), 1);
    c.erase(remove(c.begin(), c.end(), 1), c.end());
    if (c.empty()) {
      q -= 1;
      s = 1;
    } else {
      s = 0;
      for (int i = (int)(0); i < (int)(c.size()); i++) s += min(c[i], m);
      s -= 2 * (c.size() - 1);
    }
    cout << max(0, (q - s + 1) / 2) << endl;
  }
  return 0;
}
