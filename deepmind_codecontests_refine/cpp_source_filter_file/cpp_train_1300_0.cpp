#include <bits/stdc++.h>
using namespace std;
pair<int, int> p[200010];
int pos[200010], idx[200010], mp[200010];
int main() {
  int n, m;
  scanf("%d%d", &n, &m);
  for (int i = 1; i <= n; i++) scanf("%d", &p[i].first), p[i].second = i;
  sort(p + 1, p + n + 1);
  for (int i = 1; i <= n; i++)
    pos[i] = p[i].first, idx[i] = p[i].second, mp[p[i].second] = i;
  while (m--) {
    bool type = true;
    int x, len;
    scanf("%d%d", &x, &len);
    if (n == 1) {
      printf("1\n");
      continue;
    }
    x = mp[x];
    int id = upper_bound(pos + 1, pos + n + 1, pos[x] + len) - pos - 1;
    len -= pos[id] - pos[x];
    x = id;
    type = false;
    if (len >= pos[n] - pos[1]) {
      int q = len / (pos[n] - pos[1]);
      if (q % 2)
        x = 1, type = true;
      else
        x = n, type = false;
      len -= q * (pos[n] - pos[1]);
    }
    while (len) {
      if (type) {
        id = upper_bound(pos + 1, pos + n + 1, pos[x] + len) - pos - 1;
        if (id == x || pos[id] == pos[x] + len) {
          x = id;
          break;
        }
        if (pos[id] - pos[x] >= len / 2) {
          len -= (pos[id] - pos[x]);
          x = id;
          type = !type;
          continue;
        }
        int tmp = pos[id] - pos[x], q = len / tmp;
        if (q % 2)
          x = id, type = 2, len -= q * tmp;
        else
          len -= q * tmp;
      } else {
        id = lower_bound(pos + 1, pos + n + 1, pos[x] - len) - pos;
        if (id == x || pos[id] == pos[x] - len) {
          x = id;
          break;
        }
        if (pos[x] - pos[id] >= len / 2) {
          len -= (pos[x] - pos[id]);
          x = id;
          type = !type;
          continue;
        }
        int tmp = (pos[x] - pos[id]), q = len / tmp;
        if (q % 2)
          x = id, type = true, len -= q * tmp;
        else
          len -= q * tmp;
      }
    }
    printf("%d\n", idx[x]);
  }
}
