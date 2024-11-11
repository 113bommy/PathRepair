#include <bits/stdc++.h>
using namespace std;
void ASS(bool b) {
  if (!b) {
    ++*(int*)0;
  }
}
const int K = 4;
struct S {
  int a[K];
  S() {
    memset(a, 0, sizeof(a));
    a[0] = -1;
  }
  S op(int x, int y, int z, int k) {
    S res = *this;
    res.a[x] = a[y] + k * a[z];
    return res;
  }
  bool contain(int x) {
    for (int i = 0; i < (int)(K); i++)
      if (a[i] == x) return 1;
    return 0;
  }
  bool bad(int x) {
    for (int i = 0; i < (int)(K); i++)
      if (a[i] > x) return 1;
    return 0;
  }
};
bool operator<(const S& a, const S& b) {
  return memcmp(&a.a, &b.a, sizeof(a.a)) < 0;
}
bool operator==(const S& a, const S& b) {
  return memcmp(&a.a, &b.a, sizeof(a.a)) == 0;
}
map<S, S> d;
queue<S> q;
void add(const S& x, const S& y) {
  S& dd = d[x];
  if (dd.a[0] != -1) return;
  dd = y;
  q.push(x);
}
string toS(int x) {
  char buf[16];
  sprintf(buf, "e%cx", (char)('a' + x));
  return buf;
}
string toI(int x) {
  char buf[16];
  sprintf(buf, "%d", x);
  return buf;
}
int main() {
  int n;
  cin >> n;
  S x;
  x.a[0] = 1;
  S x0 = x;
  add(x, x);
  S y;
  vector<int> vk;
  vk.push_back(0);
  vk.push_back(1);
  vk.push_back(2);
  vk.push_back(4);
  vk.push_back(8);
  while (!q.empty()) {
    x = q.front();
    q.pop();
    bool ok = 0;
    for (int a = 0; a < (int)(K); a++)
      for (int b = 0; b < (int)(K); b++)
        for (int c = 0; c < (int)(K); c++)
          for (int z = 0; z < (int)(vk.size()); z++) {
            if (ok) continue;
            int k = vk[z];
            S t = x.op(a, b, c, k);
            if (!t.bad(n)) {
              add(t, x);
            }
            if (t.contain(n)) {
              ok = 1;
              y = t;
              break;
            }
          }
    if (ok) break;
  }
  if (y.a[0] == -1) {
    cout << "ppc" << endl;
    return 0;
  }
  vector<string> ans;
  while (!(x0 == y)) {
    x = d[y];
    bool ok = 0;
    for (int a = 0; a < (int)(K); a++)
      for (int b = 0; b < (int)(K); b++)
        for (int c = 0; c < (int)(K); c++)
          for (int z = 0; z < (int)(vk.size()); z++) {
            int k = vk[z];
            if (!ok) {
              S t = x.op(a, b, c, k);
              if (y == t) {
                ok = 1;
                string s = "lea " + toS(a);
                if (k == 0)
                  s += ", [" + toS(b) + "]";
                else {
                  if (k > 1)
                    s += ", [" + toS(b) + " " + toI(k) + "*" + toS(c) + "]";
                  else
                    s += ", [" + toS(b) + " " + toS(c) + "]";
                }
                ans.push_back(s);
              }
            }
          }
    y = x;
  }
  cout << ans.size() << endl;
  reverse(ans.begin(), ans.end());
  for (int i = 0; i < (int)(ans.size()); i++) cout << ans[i] << endl;
  return 0;
}
