#include <bits/stdc++.h>
using namespace std;
const int N = 3000;
pair<int, int> a[N];
int deg[N];
class SparseTable {
  vector<vector<int> > table;
  vector<int> *a;

 public:
  SparseTable(vector<int> &v) {
    a = &v;
    int n = a->size();
    table.resize(32 - __builtin_clz(n));
    table[0].resize(n);
    for (int i = 0; i < n; ++i) table[0][i] = i;
    for (int i = 1, j = 2; j <= n; ++i, j <<= 1) {
      table[i].resize(n - j + 1);
      for (int k = 0; k < n - j; ++k)
        table[i][k] = a->at(table[i - 1][k]) > a->at(table[i - 1][k + (j >> 1)])
                          ? table[i - 1][k]
                          : table[i - 1][k + (j >> 1)];
    }
  }
  int query(int l, int r);
};
int SparseTable::query(int l, int r) {
  int lg = 31 - __builtin_clz(r - l + 1);
  return a->at(table[lg][l]) > a->at(table[lg][r - (1 << lg) + 1])
             ? table[lg][l]
             : table[lg][r - (1 << lg) + 1];
}
struct triple {
  int first, second, third;
};
int main() {
  int n;
  scanf("%d", &n);
  for (int i = 0; i < n; ++i) {
    scanf("%d", &a[i].first);
    a[i].second = i;
  }
  sort(a, a + n, greater<pair<int, int> >());
  int c_1 = 0;
  pair<int, vector<int> > c1(-1, vector<int>());
  for (int i = 0; i < n - 1; ++i)
    if (2 * (i / 2 + 1) + i + 1 <= n) {
      if (a[i].first - a[i + 1].first > c1.first) {
        c1.first = a[i].first - a[i + 1].first;
        c1.second.clear();
        c1.second.push_back(i);
      } else if (a[i].first - a[i + 1].first == c1.first)
        c1.second.push_back(i);
    }
  pair<int, vector<pair<int, int> > > c2(-1, vector<pair<int, int> >());
  for (int i = 0; i < c1.second.size(); ++i) {
    for (int j = c1.second[i] + 1; j < n - 1; ++j)
      if (2 * (j - c1.second[i]) >= c1.second[i] + 1 &&
          2 * (c1.second[i] + 1) >= j - c1.second[i] &&
          2 * (n - j - 1) >= max(j - c1.second[i], c1.second[i] + 1)) {
        if (c2.first < a[j].first - a[j + 1].first) {
          c2.first = a[j].first - a[j + 1].first;
          c2.second.clear();
          c2.second.push_back(make_pair(c1.second[i], j));
        } else if (a[j].first - a[j + 1].first == c2.first)
          c2.second.push_back(make_pair(c1.second[i], j));
      }
  }
  pair<int, triple> c3(-1, triple());
  vector<int> v(n + 1, 0);
  for (int i = 0; i < n; ++i) v[i] = a[i].first - a[i + 1].first;
  SparseTable table(v);
  for (int i = 0; i < c2.second.size(); ++i) {
    int f = c2.second[i].first;
    int s = c2.second[i].second;
    int l = max(s + 1, s + (max(f + 1, s - f) - 1) / 2 + 1);
    int r = min(n - 1, s + min(f + 1, s - f) * 2);
    if (l > r) continue;
    int ind = table.query(l, r);
    if (v[ind] > c3.first) {
      c3.first = v[ind];
      c3.second.first = c2.second[i].first;
      c3.second.second = c2.second[i].second;
      c3.second.third = ind;
    }
  }
  for (int i = 0; i <= c3.second.first; ++i) deg[a[i].second] = 1;
  for (int i = c3.second.first + 1; i <= c3.second.second; ++i)
    deg[a[i].second] = 2;
  for (int i = c3.second.second + 1; i <= c3.second.third; ++i)
    deg[a[i].second] = 3;
  for (int i = 0; i < n; ++i) printf("%d ", deg[i] ? deg[i] : -1);
  printf("\n");
  return 0;
}
