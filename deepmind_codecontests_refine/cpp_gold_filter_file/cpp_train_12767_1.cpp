#include <bits/stdc++.h>
using std::string;
char s[10];
namespace solver1 {
string f[1 << 8][3], ans[1 << 8];
const int X = 0xf, Y = 0x33, Z = 0x55, FULL = 0xff;
bool cmp(string a, string b) {
  return a.length() == b.length() ? a < b : a.length() < b.length();
}
struct Exp {
  string s;
  int p, t;
  Exp(string _s, int _p, int _t) : s(_s), p(_p), t(_t) {}
  bool operator<(const Exp& __op) const { return cmp(s, __op.s); }
  bool operator>(const Exp& __op) const { return cmp(__op.s, s); }
};
std::priority_queue<Exp, std::vector<Exp>, std::greater<Exp> > pq;
void update(Exp a) {
  if (f[a.t][a.p].empty() || cmp(a.s, f[a.t][a.p])) {
    f[a.t][a.p] = a.s;
    pq.push(a);
  }
}
void init() {
  update(Exp("x", 2, X));
  update(Exp("y", 2, Y));
  update(Exp("z", 2, Z));
  while (!pq.empty()) {
    Exp u = pq.top();
    pq.pop();
    if (u.p == 2) {
      update(Exp("!" + u.s, 2, u.t ^ FULL));
      update(Exp(u.s, 1, u.t));
    } else if (u.p == 1) {
      for (int mask = 0; mask <= FULL; mask++) {
        if (!f[mask][2].empty()) {
          update(Exp(f[mask][2] + "&" + u.s, 1, mask & u.t));
          update(Exp(u.s + "&" + f[mask][2], 1, mask & u.t));
        }
      }
      update(Exp("(" + u.s + ")", 2, u.t));
      update(Exp(u.s, 0, u.t));
    } else {
      for (int mask = 0; mask <= FULL; mask++) {
        for (int p = 0; p <= 2; p++) {
          if (!f[mask][p].empty()) {
            update(Exp(f[mask][p] + '|' + u.s, 0, mask | u.t));
            update(Exp(u.s + '|' + f[mask][p], 0, mask | u.t));
          }
        }
      }
      update(Exp("(" + u.s + ")", 2, u.t));
    }
  }
  for (int mask = 0; mask <= FULL; mask++) {
    ans[mask] = f[mask][0];
    if (cmp(f[mask][1], ans[mask])) ans[mask] = f[mask][1];
    if (cmp(f[mask][2], ans[mask])) ans[mask] = f[mask][2];
  }
}
void main() {
  int ret = 0;
  for (int i = 0; i < 8; i++) {
    ret = (ret << 1) | (s[i] == '1');
  }
  std::cout << ans[ret] << std::endl;
}
}  // namespace solver1
int main() {
  int t;
  scanf("%d", &t);
  solver1::init();
  while (t--) {
    scanf("%s", s);
    solver1::main();
  }
}
