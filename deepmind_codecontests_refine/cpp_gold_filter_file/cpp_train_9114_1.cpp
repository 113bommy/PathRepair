#include <bits/stdc++.h>
using namespace std;
int n, m, s[200005], red[200005], ans, ared;
int res[200005];
struct cpu {
  int id, val, mat;
  bool operator<(const cpu& k) const { return val > k.val; }
};
cpu t[200005];
struct ada {
  int id, val, cred;
  bool operator<(const ada& k) const {
    return val < k.val || (val == k.val && cred > k.cred);
  }
};
priority_queue<ada> Q;
int main() {
  scanf("%d %d", &n, &m);
  for (int i = (1); i <= (n); i++) {
    scanf("%d", &t[i].val);
    t[i].id = i;
    t[i].mat = 0;
  }
  sort(t + 1, t + n + 1);
  for (int i = (1); i <= (m); i++) {
    scanf("%d", &s[i]);
    Q.push((ada){i, s[i], 0});
  }
  for (int i = (1); i <= (n); i++) {
    while (!Q.empty()) {
      ada cur = Q.top();
      if (cur.val < t[i].val)
        break;
      else if (cur.val > t[i].val) {
        Q.pop();
        cur.val = (cur.val + 1) / 2;
        cur.cred++;
        Q.push(cur);
      } else {
        Q.pop();
        ans++;
        ared += cur.cred;
        t[i].mat = cur.id;
        red[cur.id] = cur.cred;
        break;
      }
    }
  }
  printf("%d %d\n", ans, ared);
  for (int i = (1); i <= (m); i++) printf("%d%c", red[i], i == m ? '\n' : ' ');
  for (int i = (1); i <= (n); i++) res[t[i].id] = t[i].mat;
  for (int i = (1); i <= (n); i++) printf("%d%c", res[i], i == n ? '\n' : ' ');
  return 0;
}
