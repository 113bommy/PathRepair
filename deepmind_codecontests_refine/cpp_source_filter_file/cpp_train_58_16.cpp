#include <bits/stdc++.h>
using namespace std;
int n, L, cnt;
int occ[1111];
pair<int, int> q[1111];
bool chk(int st, int len) {
  for (int i = st; i < st + len; i++)
    if (occ[i]) return false;
  return true;
}
void mset(int l, int r, int val) {
  for (int i = l; i <= r; i++) occ[i] = val;
}
int main() {
  scanf("%d%d", &n, &L);
  cnt = 0;
  for (int i = 0; i < n; i++) {
    char s[22];
    scanf("%s", s);
    if (s[0] == 'a') {
      int sz;
      scanf("%d", &sz);
      int found = 0;
      for (int i = 1; i <= L - sz + 1 && !found; i++)
        if (!occ[i] && chk(i, sz)) found = i;
      if (!found)
        puts("NULL");
      else {
        q[++cnt] = make_pair(found, found + sz - 1);
        mset(found, found + sz - 1, cnt);
        printf("%d\n", cnt);
      }
    } else if (s[0] == 'e') {
      int id;
      scanf("%d", &id);
      if (id < 1 || id > cnt || q[id].first == -1)
        puts("ILLEGAL_ERASE_ARGUMENT");
      else {
        mset(q[id].first, q[id].second, 0);
        q[id] = make_pair(-1, -1);
      }
    } else {
      int st = 1;
      for (int i = 1; i <= L; i++)
        if (occ[i]) {
          int id = occ[i];
          if (i < st) {
            int len = q[id].second - q[id].first + 1;
            mset(q[id].first, q[id].second, 0);
            q[id].first = st;
            q[id].second = st + len - 1;
            mset(q[id].first, q[id].second, id);
          }
          st = q[id].second + 1;
        }
    }
  }
  return 0;
}
