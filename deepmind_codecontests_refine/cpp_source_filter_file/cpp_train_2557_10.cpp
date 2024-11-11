#include <bits/stdc++.h>
using namespace std;
struct dis {
  int p[2000010], c[2000010];
  void init(int n) {
    for (int i = 0; i < n; i++) {
      p[i] = i;
      c[i] = 1;
    }
  }
  int root(int i) { return i == p[i] ? i : (p[i] = root(p[i])); }
  void step(int i, int j) {
    i = root(i);
    j = root(j);
    if (i == j) return;
    if (c[i] > c[j]) {
      swap(i, j);
    }
    p[i] = j;
    c[j] += c[i];
  }
} ds;
int main() {
  int n, m, k;
  vector<int> c;
  scanf("%d%d%d", &n, &m, &k);
  ds.init(n);
  for (int i = 0; i < m; i++) {
    int a, b;
    scanf("%d%d", &a, &b);
    ds.step(a - 1, b - 1);
  }
  for (int i = 0; i < n; i++) {
    if (ds.root(i) == i) {
      c.push_back(ds.c[i]);
    }
  }
  int s, q;
  if (c.size() == 1)
    cout << 0;
  else if (k == 1)
    cout << max(0, (int)c.size() - 2);
  else {
    q = count(c.begin(), c.end(), 1);
    c.erase(remove(c.begin(), c.end(), 1), c.end());
    if (c.empty()) {
      q = q - 1;
      s = 1;
    } else {
      s = 0;
      for (int i = 0; i < (int)c.size(); i++) {
        s += min(c[i], k);
      }
      s -= 2 * (c.size() - 1);
    }
    cout << (q - s + 1) / 2;
  }
  return 0;
}
