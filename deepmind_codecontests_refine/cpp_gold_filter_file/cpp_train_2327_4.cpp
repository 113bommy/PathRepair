#include <bits/stdc++.h>
using namespace std;
struct Rec {
  int v, l, r;
  Rec() {}
  Rec(int a, int b, int c) { v = a, l = b, r = c; }
  bool operator<(const Rec &b) const { return v < b.v; }
};
set<Rec> st;
set<Rec>::iterator it;
vector<Rec> v;
int n, same = 0;
int main() {
  scanf("%d", &n);
  for (int i = 0; i < n; i++) {
    int l, r;
    scanf("%d %d", &l, &r);
    it = st.find(Rec(l, 0, 0));
    if (it != st.end()) {
      int a = it->v, b = it->l, c = it->r;
      st.erase(it);
      st.insert(Rec(a, b + 1, c));
    } else
      st.insert(Rec(l, 1, 0));
    if (l != r) {
      it = st.find(Rec(r, 0, 0));
      if (it != st.end()) {
        int a = it->v, b = it->l, c = it->r;
        st.erase(it);
        st.insert(Rec(a, b, c + 1));
      } else
        st.insert(Rec(r, 0, 1));
    }
  }
  for (it = st.begin(); it != st.end(); it++)
    v.push_back(Rec(it->v, it->l, it->r));
  int ans = 0x3f3f3f3f;
  int m = v.size();
  for (int i = 0; i < m; i++) {
    int l = v[i].l, r = v[i].r;
    if (l + r >= (n + 1) / 2) ans = min(ans, max(0, (n + 1) / 2 - l));
  }
  if (ans == 0x3f3f3f3f) ans = -1;
  printf("%d\n", ans);
  return 0;
}
