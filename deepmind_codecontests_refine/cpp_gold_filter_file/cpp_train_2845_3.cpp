#include <bits/stdc++.h>
using namespace std;
int n, Q;
int pri[101000], prm, v[101000], u[101000];
set<int> hv[101000];
void init() {
  for (int i = 2; i <= n; i++) {
    if (!v[i]) {
      pri[++prm] = i;
      v[i] = i;
    }
    for (int j = 1; j <= prm && pri[j] * i <= n; j++) {
      v[pri[j] * i] = pri[j];
      if (i % pri[j] == 0) break;
    }
  }
}
int main() {
  scanf("%d%d", &n, &Q);
  init();
  for (char ch[2]; Q; Q--) {
    int x;
    scanf("%s", ch);
    scanf("%d", &x);
    if (ch[0] == '+') {
      if (u[x])
        printf("Already on\n");
      else {
        int y = x, t = 0;
        bool flag = true;
        while (y != 1) {
          if (hv[v[y]].size()) {
            flag = false;
            t = *hv[v[y]].begin();
          }
          y /= v[y];
        }
        if (!flag)
          printf("Conflict with %d\n", t);
        else {
          y = x;
          u[x] = 1;
          while (y != 1) {
            hv[v[y]].insert(x);
            y /= v[y];
          }
          printf("Success\n");
        }
      }
    }
    if (ch[0] == '-') {
      if (!u[x])
        printf("Already off\n");
      else {
        int y = x;
        u[x] = 0;
        while (y != 1) {
          hv[v[y]].erase(x);
          y /= v[y];
        }
        printf("Success\n");
      }
    }
  }
  return 0;
}
