#include <bits/stdc++.h>
#pragma comment(linker, "/stack:64000000")
using namespace std;
const long long INF = 1000000001;
const long double EPS = 1E-3;
const int MAXN = 100500;
void add(vector<int>& f, int pos, int val) {
  while (pos < (int)(f).size()) {
    f[pos] += val;
    pos = (pos | (pos + 1));
  }
}
int get(vector<int>& f, int pos) {
  int res = 0;
  while (pos >= 0) {
    res += f[pos];
    pos = (pos & (pos + 1)) - 1;
  }
  return res;
}
int firstFree(vector<int>& f, int pos) {
  int pr = 0;
  if (pos) pr = get(f, pos - 1);
  int l, r, sum = 0;
  if (get(f, (int)(f).size() - 1) - pr == (int)(f).size() - pos) {
    l = 0;
    r = pos - 1;
  } else {
    l = pos;
    sum = pr;
    r = (int)(f).size() - 1;
  }
  while (l < r) {
    int mid = (l + r) / 2;
    int cur = get(f, mid);
    if (cur - sum == mid - l + 1) {
      sum = cur;
      l = mid + 1;
    } else {
      r = mid;
    }
  }
  return l;
}
vector<vector<int> > f;
int n, m, h;
vector<pair<int, int> > ids;
struct rec {
  int op, id, h;
  rec() {}
};
vector<rec> r;
int gcd(int a, int b) { return a && b ? gcd(b % a, a) : a + b; }
vector<int> used;
char buff[1000];
map<int, int> wh;
vector<int> inv;
int main() {
  scanf("%d%d%d", &h, &m, &n);
  int g = gcd(h, m);
  f.resize(g);
  int sz = h / g;
  for (int i = 0; i < (int)g; i++) {
    f[i].assign(sz, 0);
  }
  inv.resize(sz);
  int pos = 0;
  for (int i = 0; i < (int)sz; i++) {
    inv[pos] = i;
    pos = (pos + m / g) % sz;
  }
  r.resize(n);
  for (int i = 0; i < (int)n; i++) {
    gets(buff);
    char c;
    scanf("%c%d", &c, &r[i].id);
    if (c == '+') {
      r[i].op = 1;
      scanf("%d", &r[i].h);
      ids.push_back(make_pair(r[i].id, i));
    } else {
      r[i].op = 0;
    }
  }
  sort((ids).begin(), (ids).end());
  long long res = 0;
  long long gres = 0;
  used.assign(h, -1);
  for (int i = 0; i < (int)n; i++) {
    if (r[i].op) {
      int mod = r[i].h % g;
      int pos = inv[r[i].h / g];
      int npos = firstFree(f[mod], pos);
      res += (npos - pos + sz) % sz;
      add(f[mod], npos, 1);
      r[i].op = npos;
    } else {
      int pos = lower_bound((ids).begin(), (ids).end(), make_pair(r[i].id, 0)) -
                ids.begin();
      pos = ids[pos].second;
      int mod = r[pos].h % g;
      pos = r[pos].op;
      add(f[mod], pos, -1);
    }
  }
  cout << res << endl;
}
