#include <bits/stdc++.h>
using namespace std;
int t[500000];
void build(int a[], int v, int tl, int tr) {
  if (tl == tr)
    t[v] = a[tl];
  else {
    int tm = (tl + tr) / 2;
    build(a, v * 2, tl, tm);
    build(a, v * 2 + 1, tm + 1, tr);
    t[v] = t[v * 2] + t[v * 2 + 1];
  }
}
int sum(int v, int tl, int tr, int l, int r) {
  if (l > r) return 0;
  if (l == tl && r == tr) return t[v];
  int tm = (tl + tr) / 2;
  return sum(v * 2, tl, tm, l, min(r, tm)) +
         sum(v * 2 + 1, tm + 1, tr, max(l, tm + 1), r);
}
vector<int> z_function(string s) {
  int n = (int)s.length();
  vector<int> z(n);
  for (int i = 1, l = 0, r = 0; i < n; ++i) {
    if (i <= r) z[i] = min(r - i + 1, z[i - l]);
    while (i + z[i] < n && s[z[i]] == s[i + z[i]]) ++z[i];
    if (i + z[i] - 1 > r) l = i, r = i + z[i] - 1;
  }
  return z;
}
int a[100500];
int main(void) {
  string s;
  cin >> s;
  int l = s.size();
  vector<int> p = z_function(s);
  p[0] = s.size();
  for (vector<int>::iterator it = p.begin(); it < p.end(); it++) {
    a[*it]++;
  }
  build(a, 1, 0, 100100);
  queue<int> qq;
  for (int i = 1; i <= s.size(); i++) {
    if (p[l - i] == i) qq.push(i);
  }
  cout << s.size() << endl;
  while (!qq.empty()) {
    int i = qq.front();
    printf("%d ", i);
    printf("%d\n", sum(1, 0, 100100, i, 100099));
    qq.pop();
  }
  return 0;
}
