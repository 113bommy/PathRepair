#include <bits/stdc++.h>
using namespace std;
const int N = 1005;
int l[N], p[N];
bitset<N * N> f[N];
bool spliter(int a[N], int n, vector<int>& x, vector<int>& y) {
  int sum = 0;
  for (int i = 0; i < n; i++) {
    sum += a[i];
  }
  if (sum & 1) return false;
  f[0].set(0);
  for (int i = 0; i < n; i++) {
    f[i + 1] = f[i] << a[i];
    f[i + 1] |= f[i];
  }
  int cur = sum / 2;
  if (!f[n][cur]) return false;
  for (int i = n - 1; i >= 0; i--) {
    int nxt = cur - a[i];
    if (nxt >= 0 && f[i][nxt]) {
      cur = nxt;
      x.push_back(a[i]);
    } else {
      y.push_back(a[i]);
    }
  }
  assert(cur == 0);
  return true;
}
struct point {
  int x, y;
  point operator+(const point& p) const { return {x + p.x, y + p.y}; }
  point& operator+=(const point& p) {
    x += p.x;
    y += p.y;
    return *this;
  }
  void print() { printf("%d %d\n", x, y); }
};
struct upper {
  int h, v;
  void run(point& p) {
    p.x -= h;
    p.print();
    p.y -= v;
    p.print();
  }
  bool operator<(const upper& other) const { return h * other.v > v * other.h; }
};
struct lower {
  int h, v;
  void run(point& p) {
    p.x += h;
    p.print();
    p.y += v;
    p.print();
  }
  bool operator<(const lower& other) const { return h * other.v > v * other.h; }
};
int main() {
  int t;
  scanf("%d", &t);
  while (t--) {
    int h, v;
    scanf("%d", &h);
    for (int i = 0; i < h; i++) scanf("%d", l + i);
    scanf("%d", &v);
    for (int i = 0; i < v; i++) scanf("%d", p + i);
    if (h != v) {
      puts("No");
      continue;
    }
    vector<int>* h1 = new vector<int>();
    vector<int>* h2 = new vector<int>();
    vector<int>* v1 = new vector<int>();
    vector<int>* v2 = new vector<int>();
    if (!spliter(l, h, *h1, *h2) || !spliter(p, v, *v1, *v2)) {
      puts("No");
      continue;
    }
    if (h1->size() < h2->size()) swap(h1, h2);
    if (v1->size() < v2->size()) swap(v1, v2);
    vector<upper> uppers;
    vector<lower> lowers;
    for (int i = 0, _ = v2->size(); i < _; i++) {
      uppers.push_back({(*h1)[i], (*v2)[i]});
    }
    for (int i = 0, _ = h2->size(); i < _; i++) {
      lowers.push_back({(*h2)[i], (*v1)[i]});
    }
    sort(uppers.begin(), uppers.end());
    sort(lowers.begin(), lowers.end());
    point cur{0, 0};
    puts("Yes");
    for (auto& u : lowers) {
      u.run(cur);
    }
    int re = h1->size() - v2->size();
    auto hi = h1->begin() + v2->size();
    auto vi = v1->begin() + h2->size();
    while (re--) {
      cur.x -= *hi++;
      cur.print();
      cur.y += *vi++;
      cur.print();
    }
    for (auto& u : uppers) {
      u.run(cur);
    }
    delete h1;
    delete h2;
    delete v1;
    delete v2;
  }
}
