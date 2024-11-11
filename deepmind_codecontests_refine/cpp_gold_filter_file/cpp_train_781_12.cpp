#include <bits/stdc++.h>
using namespace std;
int n, q, k, friends[150005];
struct frie {
  int t, id;
  bool operator<(const frie &p) const { return t > p.t; }
};
set<frie> online;
int main() {
  scanf("%d%d%d", &n, &k, &q);
  for (int i = 1; i <= n; i++) scanf("%d", &friends[i]);
  while (q--) {
    int op, id;
    scanf("%d", &op);
    switch (op) {
      case 1:
        scanf("%d", &id);
        online.insert((frie){friends[id], id});
        break;
      case 2:
        scanf("%d", &id);
        bool flag = false;
        int j = 1;
        for (set<frie>::iterator it = online.begin();
             it != online.end() && j <= k; it++, j++) {
          if ((*it).id == id) {
            flag = true;
            break;
          }
        }
        if (flag)
          printf("YES\n");
        else
          printf("NO\n");
        break;
    }
  }
  return 0;
}
