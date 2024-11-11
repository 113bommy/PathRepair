#include <bits/stdc++.h>
using namespace std;
const int MX = 1000005, INF = 1000010000;
const long long int LINF = 1000000000000000000ll;
const double eps = 1e-10;
const int dx[] = {-1, 0, 1, 0}, dy[] = {0, -1, 0, 1};
char in[MX];
string s;
int n, r, d;
vector<int> b;
void f(int x, vector<int>& c) {
  c.resize(r + x - 1);
  if (x == 1) {
    c = b;
    return;
  }
  for (int i = 0; i < c.size(); ++i) c[i] = i;
  vector<int> a, t;
  f(x >> 1, a);
  int ci = 0, l = a.size(), y = x >> 1;
  for (int i = 0; i < l; ++i) c[i] = a[i];
  t = c;
  for (int i = 0; i < l; ++i) c[y + i] = t[y + a[i]];
  if (x & 1) {
    t = c;
    for (int i = 0; i < r; ++i) c[y * 2 + i] = t[y * 2 + b[i]];
  }
}
int main() {
  int q;
  scanf("%s%d", in, &q);
  s = in;
  n = s.size();
  for (int qi = 0; qi < q; ++qi) {
    scanf("%d%d", &r, &d);
    vector<int> c;
    b.resize(r);
    int bi = 0;
    for (int i = 0; i < d; ++i) {
      for (int j = i; j < r; j += d) b[bi++] = j;
    }
    f(n - r + 1, c);
    string t = s;
    for (int i = 0; i < n; ++i) s[i] = t[c[i]];
    printf("%s\n", s.c_str());
  }
  return 0;
}
