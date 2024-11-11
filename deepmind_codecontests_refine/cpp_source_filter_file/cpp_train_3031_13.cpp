#include <bits/stdc++.h>
using namespace std;
struct Status {
  unsigned p[3];
  unsigned opr[3];
  inline unsigned hashCode() {
    return p[0] + p[1] * 60 + p[2] * 3600 + opr[0] * 21600 +
           ((opr[1] * 21600) << 5) + ((opr[2] * 21600) << 10);
  }
};
set<unsigned> st;
unsigned ans = 0;
inline bool haveWalked(Status s, int p) { return s.opr[p - 1] & 1; }
inline bool haveGrabbed(Status s, int p) { return s.opr[p - 1] & 2; }
inline bool haveThrown(Status s, int p) { return s.opr[p - 1] & 4; }
inline int grabbing(Status s, int p) { return s.opr[p - 1] >> 3; }
inline int isConquered(Status s, unsigned p) {
  return s.p[0] == p || s.p[1] == p || s.p[2] == p;
}
int wrange[3], trange[3];
inline void updataAnswer(Status s) {
  ans = max(ans, s.p[0]);
  ans = max(ans, s.p[1]);
  ans = max(ans, s.p[2]);
}
inline Status walkTo(Status s, int p, int to) {
  s.opr[p - 1] |= 1;
  s.p[p - 1] = to;
  return s;
}
inline Status grab(Status s, int a, int b) {
  s.opr[a - 1] |= 2;
  s.opr[a - 1] += b << 3;
  s.p[b - 1] = s.p[a - 1];
  if (grabbing(s, b)) s.p[grabbing(s, b) - 1] = s.p[a - 1];
  return s;
}
inline Status throwTo(Status s, int p, int to) {
  s.opr[p - 1] |= 4;
  s.p[grabbing(s, p) - 1] = to;
  if (grabbing(s, grabbing(s, p))) s.p[grabbing(s, grabbing(s, p)) - 1] = to;
  s.opr[p - 1] &= 7;
  return s;
}
void dfs(Status s) {
  unsigned code = s.hashCode();
  if (st.insert(code).second == false) return;
  updataAnswer(s);
  bool avlb[3];
  avlb[0] = avlb[1] = avlb[2] = true;
  for (int i = 0; i < 3; i++)
    if (grabbing(s, i + 1)) avlb[grabbing(s, i + 1) - 1] = false;
  for (int i = 0; i < 3; i++) {
    if (!avlb[i]) continue;
    if (grabbing(s, i + 1)) continue;
    if (haveWalked(s, i + 1)) continue;
    for (unsigned p = max(1, (int)s.p[i] - (int)wrange[i]);
         p <= s.p[i] + wrange[i]; p++) {
      if (isConquered(s, p)) continue;
      dfs(walkTo(s, i + 1, p));
    }
  }
  for (int i = 0; i < 3; i++) {
    if (!avlb[i]) continue;
    if (haveGrabbed(s, i + 1)) continue;
    for (int j = 0; j < 3; j++) {
      if (!avlb[j]) continue;
      if (i != j && abs((int)s.p[i] - (int)s.p[j]) == 1)
        dfs(grab(s, i + 1, j + 1));
    }
  }
  for (int i = 0; i < 3; i++) {
    if (!avlb[i]) continue;
    if (!grabbing(s, i + 1)) continue;
    for (unsigned p = max(1, (int)s.p[i] - (int)trange[i]);
         p <= s.p[i] + trange[i]; p++) {
      if (isConquered(s, p)) continue;
      dfs(throwTo(s, i + 1, p));
    }
  }
}
int main() {
  Status s;
  s.opr[0] = s.opr[1] = s.opr[2] = 0;
  for (int i = 0; i < 3; i++) scanf("%d%d%d", &s.p[i], &wrange[i], &trange[i]);
  dfs(s);
  cout << ans << '\n';
}
