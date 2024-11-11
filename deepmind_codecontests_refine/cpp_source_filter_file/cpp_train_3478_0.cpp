#include <bits/stdc++.h>
using namespace std;
using pii = pair<int, int>;
using vi = vector<int>;
using ll = long long;
int main() {
  int n;
  scanf("%d", &n);
  vector<int> c(n);
  for (int i = 0; i < n; i++) scanf("%d", &c[i]);
  vi cur;
  for (int i = 0; i < n; i++) {
    if (c[i] == 0) {
      if (cur.empty()) {
        printf("0\n");
        continue;
      }
      vi s = cur;
      sort(s.begin(), s.end(), greater<int>());
      int m = cur.size();
      if (m < 3) {
        printf("pushQueue\n");
        if (m == 2) printf("pushStack\n");
        printf("%d ", m);
        printf("popQueue ");
        if (m == 2) printf("popStack ");
        printf("\n");
      } else {
        int m1 = s[0], m2 = s[1], m3 = s[2];
        for (int x : cur) {
          if (x == m1)
            printf("pushQueue\n"), m1 = -1;
          else if (x == m2)
            printf("pushStack\n"), m2 = -2;
          else if (x == m3)
            printf("pushFront\n"), m3 = -2;
          else
            printf("pushBack\n");
        }
        printf("3 popQueue popStack popFront\n");
      }
      cur.clear();
      continue;
    }
    cur.push_back(c[i]);
  }
  for (int i = 0, m = cur.size(); i < m; i++) printf("pushStack\n");
}
