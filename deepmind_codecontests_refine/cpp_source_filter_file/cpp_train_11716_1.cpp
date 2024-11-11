#include <bits/stdc++.h>
using namespace std;
inline void splay(int &v) {
  v = 0;
  char c = 0;
  int p = 1;
  while (c < '0' || c > '9') {
    if (c == '-') p = -1;
    c = getchar();
  }
  while (c >= '0' && c <= '9') {
    v = (v << 3) + (v << 1) + c - '0';
    c = getchar();
  }
  v *= p;
}
struct p {
  int x, y, id;
  double disa, disb, disr;
  void read() { splay(x), splay(y); }
  friend bool operator<(const p &a, const p &b) { return a.id < b.id; }
} a, b, r, s[100010];
int n;
double dis(p &a, p &b) {
  return sqrt((double)(a.x - b.x) * (a.x - b.x) +
              (double)(a.y - b.y) * (a.y - b.y));
}
bool compa(const p &a, const p &b) { return a.disr - a.disa > b.disr - b.disa; }
bool compb(const p &a, const p &b) { return a.disr - a.disb > b.disr - b.disb; }
int main() {
  a.read(), b.read(), r.read();
  splay(n);
  double ans = 0;
  for (int i = 1; i <= n; i++) {
    s[i].read();
    s[i].disa = dis(s[i], a);
    s[i].disb = dis(s[i], b);
    s[i].disr = dis(s[i], r);
    ans += s[i].disr * 2;
    s[i].id = i;
  }
  sort(s + 1, s + n + 1, compa);
  int x1 = s[1].id, y1 = s[2].id;
  sort(s + 1, s + n + 1, compb);
  int x2 = s[1].id, y2 = s[2].id;
  sort(s + 1, s + n + 1);
  if (x1 != x2) {
    double ans1 = (ans - s[x1].disr + s[x1].disa - s[x2].disr + s[x2].disb);
    double ans2 = ans - s[x1].disr + s[x1].disa;
    double ans3 = ans - s[x2].disr + s[x2].disa;
    printf("%.10f", min(min(ans1, ans2), ans3));
  } else {
    double ans1 = ans - s[y1].disr + s[y1].disa - s[x2].disr + s[x2].disb;
    double ans2 = ans - s[x1].disr + s[x1].disa - s[y2].disr + s[y2].disb;
    double ans3 = ans - s[x1].disr + s[x1].disa;
    double ans4 = ans - s[x2].disr + s[x2].disa;
    printf("%.10f", (double)(min(min(ans1, ans2), min(ans3, ans4))));
  }
}
